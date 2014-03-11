#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <limits>


using namespace std;
class Solution {
    public:
        void compute(string S, int i, string T, int j, int &n) {
            if (j == T.length()) {
                n++;
                return;
            }
            if (i > S.length())
                return;
            if (S[i] == T[j]){
                compute(S, i+1, T, j+1, n);
                compute(S, i+1, T, j, n);
            } else {
                compute(S, i+1, T, j, n);
            }
        }
        int numDistinct(string S, string T) {
            int n = 0;
            compute(S, 0, T, 0, n);
            return n;
        }
};
int main()
{
    //string S("rabbbit");
    //string T("rabbit");
    //    string S("bbi");
    //    string T("bi");

    string S("aabdbaabeeadcbbdedacbbeecbabebaeeecaeabaedadcbdbcdaabebdadbbaeabdadeaabbabbecebbebcaddaacccebeaeedababedeacdeaaaeeaecbe");
    string T("bddabdcae");

    Solution SS;
    cout <<SS.numDistinct(S, T) <<endl; 

    return 0;
}

