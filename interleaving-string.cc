#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <limits>
#include <map>
using namespace std;


class Solution {
    public:

        int s1_len, s2_len, s3_len;
        bool _isInterleave(string &s1, int n1,  string &s2, int n2, string &s3, int n3, vector<vector<int> > &tab) {
            bool res = false;

            if (tab[n1][n2] != -1) {
                if (tab[n1][n2] == 1)
                    return true;
                else
                    return false;
            
            }

            if (n1 == s1_len  && n2 == s2_len && n3 == s3_len)
                return true;
            
            if (s2_len > n2 && s3_len > n3 && s2[n2] == s3[n3])
                res = _isInterleave(s1, n1, s2, n2+1, s3, n3+1, tab);

            if (res == true)
                return true;
            if (s1_len > n1 && s3_len > n3 && s1[n1] == s3[n3])
                res = _isInterleave(s1, n1+1, s2, n2, s3, n3+1, tab);

            if (res == true)
                tab[n1][n2] = 1;
            else 
                tab[n1][n2] = 0;

            return res;
        }

        bool isInterleave(string s1, string s2, string s3) {
            s1_len = s1.length();s2_len = s2.length();s3_len = s3.length();
            vector<vector<int> > tab(s1_len+1, vector<int> (s2_len+1, -1));

            return _isInterleave(s1, 0, s2, 0, s3, 0, tab);
        }
};
int main()
{
    string s1("bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa");
    string s2("babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab");
    string s3("babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaabababbaaaaaabababbababaababbababbbababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab");

/*
    string s1("aabcc");
    string s2("dbbca");
    string s3("aadbbcbcac");
*/
    Solution S;
    if (S.isInterleave(s1, s2, s3))
        cout <<"isInterleave" <<endl;

    return 0;
}

