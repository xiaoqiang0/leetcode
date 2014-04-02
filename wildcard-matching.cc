#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <limits>
#include <queue>
#include <map>

using namespace std;
class Solution {
    public:
        //find all matched pos 
        vector<int> find_all(string &s, string &p, int pre){
            vector<int> res;
            for (int i = pre; i < s.length();){
                int cur = s.find(p, i);
                if (cur == string::npos)
                    return res;
                res.push_back(cur);
                i = cur+1;
            }

            return res;
        }

        bool check(int N, int pos, vector<pair<string, vector<int> > > &v, int i, vector<vector<int> >  &C){
            if (C[i][pos] != -1) return (C[i][pos] == 1? true:false) ;

            if (i == v.size() && pos == N) {
                C[i][pos] = 1;
                return true;
            }

            //v end or [ pos at end and v[i] is not *]
            if (i == v.size() || (pos == N && v[i].first[0] != '*')){
                C[i][pos] = 0;
                return false;
            }

            string ns = v[i].first;
            vector<int> &nv = v[i].second;

            int skip = 0;
            bool res;
            bool have_star = false;
            int k = i; //var for finding first sub string in pp

            switch(ns[0]) {
                case '?':
                    res = check(N, pos + nv[0], v, i+1, C);
                    break;
                case '*':
                    have_star = true;
                    if (i == v.size()-1){
                        res = true;
                        break;
                    } else {
                        k++;
                        ns = v[k].first;
                        nv = v[k].second;
                        //Try to find a substr, then go to default lable.
                        while (ns[0] == '?' || ns[0] == '*'){
                            if (ns[0] == '?') {
                                skip += nv[0];
                                if (skip + pos > N){
                                    res = false;
                                    C[i][pos] = 0;
                                    return res;
                                }
                            }
                            k++;
                            if (k == v.size())
                                break;
                            ns = v[k].first;
                            nv = v[k].second;
                        }

                        if ((ns[0] == '?' || ns[0] == '*')){
                            // no enough chars  for '?'
                            if (skip > N - pos) {
                                res = false;
                                C[i][pos] = 0;
                            } else { // * found, so it always true
                                res = true;
                                C[i][pos] = 1;
                            }

                            return res;
                        }
                    }
                default:
                    // iterate all match position
                    for (int j = 0; j < nv.size(); j++){
                        int cur = nv[j];
                        if (cur < pos + skip) continue;

                        if (have_star == false && cur != pos) {
                            res = false;
                            break;
                        }

                        res = check(N, cur + ns.length(), v, k+1, C);
                        if (res == true){
                            res = true;
                            break;
                        }

                        // can't continue to check next if no star (*)
                        if (have_star == false){
                            res = false;
                            break;
                        }
                        nv[j] = numeric_limits<int>::min();
                    }

                    // Clear invalid match position
                    while (nv.empty() == false && nv[0] == numeric_limits<int>::min())
                        nv.erase(nv.begin());
            }

            C[i][pos] = (res == true ? 1: 0);
            return res;
        }

        bool isMatch(const char *s, const char *p) {
            string ss(s);
            string pp(p);
            vector<pair<string, vector<int> > > v;

            //matched previous position in s
            int pre = 0;

            for (int i = 0; i < pp.size();){
                int cur;
                switch (pp[i]) {
                    case '*':
                        cur = pp.find_first_not_of('*', i);
                        v.push_back(make_pair("*", vector<int>(1, -1)));
                        i  = cur;
                        break;

                    case '?':
                        cur = pp.find_first_not_of('?', i);
                        if (cur == string::npos)
                            cur = pp.length();
                        v.push_back(make_pair("?", vector<int>(1, cur-i)));
                        pre += cur-i;
                        //No enough chars for '?'s, return false directly.
                        if (pre > ss.length())
                            return false;
                        i  = cur;
                        break;
                    default:
                        cur = pp.find_first_of("*?", i);
                        string sub(pp.substr(i, cur-i));
                        vector<int> vv = find_all(ss, sub, pre);

                        // No sub string in ss can match 'sub', so return false directly
                        if (vv.size() == 0)
                            return  false;

                        // Create pair
                        v.push_back(make_pair(sub, vv));
                        i = cur;
                        // Increase pre.
                        pre = vv[0] + sub.length();
                }
            }

            vector<vector<int> >  C(v.size()+1, vector<int>(ss.length()+1, -1));

            return check(ss.length(), 0, v, 0, C);
        }
};
int main()
{
/*
    char *s = "aab";
    char *p = "c*a*b";
    char *s = "ab";
    char *p = "?*";
    char *s = "ab";
    char *p = "a*";
    char *s = "ab";
    char *p = "*";
    char *s = "aaa";
    char *p = "aa";
    char *s = "aa";
    char *p = "aa";
    char *s = "aa";
    char *p = "a";
    char *s = "aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaaba";
    char *p = "a*******b";
    char *s = "c";
    char *p = "*?*";
    char *s = "aaaabaabaabbbabaabaabbbbaabaaabaaabbabbbaaabbbbbbabababbaabbabbbbaababaaabbbababbbaabbbaabbaaabbbaabbbbbaaaabaaabaabbabbbaabababbaabbbabababbaabaaababbbbbabaababbbabbabaaaaaababbbbaabbbbaaababbbbaabbbbb";
    char *p = "**a*b*b**b*b****bb******b***babaab*ba*a*aaa***baa****b***bbbb*bbaa*a***a*a*****a*b*a*a**ba***aa*a**a*";
    char *s = "abbbaaababbaaabaaabbbabbbbaaabbaaababaabbbbbbaababbabababbababaaabbbbbabababaababaaaaaaabbbaabaabbbaabbabaababbabaababbbabbaaabbbaaaababbaaabbaabaabbbbbaaababaabaabaaabbabaabbbabbbaabbababaabbbbbbbbaaa";
    char *p = "*ba***bba*b**abbaa***a*****b*a*bb*b***a*bbb***a***bba*****a****a*a*b**aaaba*aab*a*aa***a*a*b**b**a*b*";
    char *s = "xyzabcxabc";
    char *p = "xy*?abc";
    char *s = "abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb";
    char *p =   "*aa*ba*a*bb**aa*ab****a*aaaaaa***a*aaaa**bbabb*b*b**aaaaaaaaa*a********ba*bbb***a*ba*bb*bb**a*b*bb";
    char *s = "baaaba";
    char *p = "?*?***";
    char *s = "abbaabbbbababaababababbabbbaaaabbbbaaabbbabaabbbbbabbbbabbabbaaabaaaabbbbbbaaabbabbbbababbbaaabbabbabb";
    char *p = "***b**a*a*b***b*a*b*bbb**baa*bba**b**bb***b*a*aab*a**";
    char *s = "abbaabbbbababaababababbabbbaaaabbbbaaabbbabaabbbbbabbbbabbabbaaabaaaabbbbbbaaabbabbbbababbbaaabbabbabb";
    char *p = "***b**a*a*b***b*a*b*bbb**baa*bba**b**bb***b*a*aab*a**";
*/
    string s("ab");
    string p("*a");
    Solution S;
    cout << S.isMatch(s.c_str(), p.c_str()) <<endl;

    return 0;
}
