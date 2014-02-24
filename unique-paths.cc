#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;
class Solution {
    public:
        int _uniquePaths(int m, int n, vector<vector<int> > &A) {

            if (A[m][n] != 0) return A[m][n];
            if (m == 1 || n == 1) {
                A[m][n] = 1;
                return A[m][n];
            }
            A[m][n] = _uniquePaths(m-1, n, A) + _uniquePaths(m, n-1, A);

            return A[m][n];
        }

        int uniquePaths(int m, int n) {
            vector<vector<int> > A;
            for (int i = 0; i <= m; i++) {
                vector<int> t(n+1, 0);
                A.push_back(t);
            }
            A[1][1] = 1;
            _uniquePaths(m, n, A);

            return A[m][n];
        }
        /* Version 2
           int uniquePaths(int m, int n) {
           if (m == 1|| n == 1) return 1;
           return uniquePaths(m - 1, n) + uniquePaths(m, n -1);
           } */
};

int main()
{
    Solution S;
    for (int i = 1; i <= 5; i ++)
        for (int j = 1; j <= 8; j++)
            cout << "uniquePaths["<<i<<"]["<<j <<"] :is " << S.uniquePaths(i, j)<<endl;

    return 0;
}
