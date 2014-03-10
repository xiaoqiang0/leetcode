#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <set>
#include <limits>

/*
#        Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.
#        Below is one possible representation of s1 = "great":
#            great
#           /    \
#          gr    eat
#         / \    /  \
#        g   r  e   at
#                   / \
#                  a   t
#        To scramble the string, we may choose any non-leaf node and swap its two children.
#        For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".
#            rgeat
#           /    \
#          rg    eat
#         / \    /  \
#        r   g  e   at
#                   / \
#                  a   t
#        We say that "rgeat" is a scrambled string of "great".
#        Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".
#            rgtae
#           /    \
#          rg    tae
#         / \    /  \
#        r   g  ta  e
#               / \
#              t   a
#        We say that "rgtae" is a scrambled string of "great".
#        Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1. 
 */

using namespace std;
class Solution {
public:
    bool gen(string s1, int l1, int u1, string s2, int l2, int u2)
    {
        bool res = false;
        if (l1 == u1 && l2 == u2 && s1[l1] == s2[l2])
            return true;

        for (int i = l1; i < u1; i++) {
            string s1_l(s1.substr(l1, i - l1 + 1));
            string s1_r(s1.substr(i+1, u1-i));
            
            string s2_l(s2.substr(l2, i - l1 + 1));
            string s2_r(s2.substr(l2 + (i-l1) + 1, u1-i));
            
            sort(s1_l.begin(), s1_l.end());
            sort(s1_r.begin(), s1_r.end());
        
            sort(s2_l.begin(), s2_l.end());
            sort(s2_r.begin(), s2_r.end());
            
            if (s1_l.compare(s2_l) == 0 && s1_r.compare(s2_r) == 0)
                res = res || (gen(s1, l1, i,  s2, l2, l2 + (i - l1) ) && \
                              gen(s1, i+1, u1,s2, l2 + (i - l1) + 1, u2));
            
            if (res == true)
                return true;

            s2_l = s2.substr(l2, (u1 - i));
            s2_r = s2.substr(l2 +(u1 - i), i - l1 +1);

            sort(s2_l.begin(), s2_l.end());
            sort(s2_r.begin(), s2_r.end());

            if (s1_l.compare(s2_r) == 0 && s1_r.compare(s2_l) == 0)
                res = res || (gen(s1, l1, i,s2, u2 - (i - l1), u2) ) && \
                              gen(s1, i+1, u1, s2, l2, u2 - (i - l1) - 1 );

            if (res == true)
                return true;
        }

        return res;
    }
    bool isScramble(string s1, string s2) {
        vector<char> cur;
        return gen(s1, 0, s1.length()-1, s2, 0, s2.length()-1);

/*
        for (set <string>::iterator it= ret.begin() ; it != ret.end(); it++)
            cout <<  *it <<endl;
*/
    }
};
int main()
{
    Solution S;
    //string s1("egr");
    //string s2("gre");
    string s1("great");
    string s2("rgeat");
    //string s1("abcdefghijklmn");
    //string s2("efghijklmncadb");

    if (S.isScramble(s1,s2))
        cout <<"OK" <<endl;

    cout <<endl;
    return 0;
}
