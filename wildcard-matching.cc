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
        bool eval(string &s, int i, string &p, int j, vector<vector<int> >&v) {
            bool res;
            if (s.length() < i || p.length() < j) return false;
            if (i == s.length() && j == p.length()) return true;
            //p is not start with x*
            if (!(j < p.length() && p[j] == '*'))
                if (!(i < s.length() && j < p.length() )) {
                    return false;
                }
            
            if (i == s.length() && p.find_first_not_of("*?", j) != string::npos){
                res = false;
                if (res == false)
                    v[i][j] = 0;
                else
                    v[i][j] = 1;
                return res;
            }
            if (v[i][j] != -1)
                return v[i][j] == 1?true:false;
            while (j < p.length()-1 && p[j] == '*' && p[j+1] == '*')
                j++;
            if (p[j] == '?') {
                res = (i < s.length() && eval(s, i+1,p, j+1, v));
                if (res == false)
                    v[i][j] = 0;
                else
                    v[i][j] = 1;
                return res;
            }
            
            if (p[j] == '*'){
                int k = p.find_first_of("*?", j+1);
                if (k == j+1) { //*?....
                    res = (i < s.length() && eval(s, i+1,p, j, v)) || eval(s, i,p, j+1, v);
                    if (res == false)
                        v[i][j] = 0;
                    else
                        v[i][j] = 1;
                    return res;
                }
                string sub = p.substr(j+1, k-j-1);
                int found = i;
                bool res = false;
                found = s.find(sub, found);
                if (found == string::npos) {
                    v[i][j] = 0;
                    return false;
                }
                res = eval(s, found+sub.length(), p, j+sub.length()+1, v) || eval(s, found+1, p, j, v);
                if (res == true) {
                    v[i][j] = 1;
                    return true;
                }

            } else {
                res = (s[i] == p[j] && eval(s, i+1, p, j+1, v));
                if (res == false)
                    v[i][j] = 0;
                else
                    v[i][j] = 1;
                return res;
            }
        
        }
        bool isMatch(const char *s, const char *p) {
            string ss(s);
            string pp(p);
            //if (ss.length() >= 200)
            //    return false;
            vector<vector<int> >v(ss.length()+1, vector<int>(pp.length()+1, -1));
            return eval(ss, 0, pp, 0, v);
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
    char *s = "abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb";
    char *p = "**aa*****ba*a*bb**aa*ab****a*aaaaaa***a*aaaa**bbabb*b*b**aaaaaaaaa*a********ba*bbb***a*ba*bb*bb**a*b*bb";
    char *s = "c";
    char *p = "*?*";
*/
    char *s = "aaaabaabaabbbabaabaabbbbaabaaabaaabbabbbaaabbbbbbabababbaabbabbbbaababaaabbbababbbaabbbaabbaaabbbaabbbbbaaaabaaabaabbabbbaabababbaabbbabababbaabaaababbbbbabaababbbabbabaaaaaababbbbaabbbbaaababbbbaabbbbb";
    char *p = "**a*b*b**b*b****bb******b***babaab*ba*a*aaa***baa****b***bbbb*bbaa*a***a*a*****a*b*a*a**ba***aa*a**a*";
    Solution S;
    cout << S.isMatch(s, p) <<endl;

    return 0;
}
