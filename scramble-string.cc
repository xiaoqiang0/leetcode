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
    set <string> gen(string s, int l, int u, vector<vector<set<string> > > &tab)
    {
        set <string> ret;
        set <string> left;
        set <string> right;
        if (tab[l][u].empty() == false)
            return tab[l][u];

        if (l == u){
            ret.insert(string(1, s[l]));
            tab[l][u] = ret;
            return ret;
        }

        for (int i = l; i < u; i++){
            left = gen(s, l, i, tab);
            right = gen(s, i+1, u, tab);
            for (set <string>::iterator it= left.begin() ; it != left.end(); it++)
                for (set <string>::iterator itr= right.begin() ; itr != right.end(); itr++) {
                    ret.insert(*it + *itr);
                    ret.insert(*itr + *it);
                }
        }

        tab[l][u] = ret;
        return ret;

    }
    bool isScramble(string s1, string s2) {
        vector<char> cur;
        set <string> ret;
        vector<vector<set<string> > > tab(s1.length()+1, vector<set<string> > (s2.length()+1, set<string>()));
        ret = gen(s1, 0, s1.length()-1, tab);

        if (ret.find(s2) == ret.end())
            return false;
        return true;

/*
        for (set <string>::iterator it= ret.begin() ; it != ret.end(); it++)
            cout <<  *it <<endl;
*/
    }
};
int main()
{
    Solution S;
    //string s1("great");
    //string s2("rgeat");
    string s1("abcdefghijklmn");
    string s2("efghijklmncadb");

    if (S.isScramble(s1,s2))
        cout <<"OK" <<endl;

    cout <<endl;
    return 0;
}
