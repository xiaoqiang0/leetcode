#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <limits>

using namespace std;
class Solution {
    public:
/*
        |
        | d(i-1, j-1) if word2
        |
d(i,j) =| 
        |
        |
        |

 */
        int compute(string s1, string s2, vector<vector<int> > &d)
        {
            ;
        }
        int minDistance(string word1, string word2) {
            vector<vector<int> > d(word1.size()+1, vector<int>(word2.size()+1, 0));
            //compute(word1, word1.size(), word2, word2.size(), v)
            int m = word1.size(), n = word2.size();
            for (int i = 0; i <= m; i++)
                d[i][0] = i; //delete
            for (int i = 0; i <= n; i++)
                d[0][i] = i; //insert

            for (int i = 1; i <= m; i++)
                for (int j = 1; j <= n; j++){
                    d[i][j] = 100000;
                    if (word1[i-1] == word2[j-1]) //same
                        d[i][j] = d[i-1][j-1];
                    if (word1[i-1] != word2[j-1] && d[i-1][j-1]+1<d[i][j]) //change
                        d[i][j] = d[i-1][j-1]+1;
                    if (d[i-1][j] + 1 < d[i][j])
                        d[i][j] = d[i-1][j] + 1;
                    if (d[i][j-1] + 1 < d[i][j])
                        d[i][j] = d[i][j-1] + 1;
                }

            return d[m][n];
        }
};
int main()
{
    string s1("a");
    string s2("b");
    Solution S;
    cout <<S.minDistance(s1, s2) <<endl;;
    return 0;
}
