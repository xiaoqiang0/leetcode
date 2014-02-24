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
        int _uniquePathsWithObstacles(int m, int n, vector<vector<int> > &A, vector<vector<int> > &obstacleGrid) {
            if (obstacleGrid[m-1][n-1] == 1){
                return 0;
            }

            if (A[m][n] != 0) return A[m][n];

            if (m == 1 || n == 1) {
                A[m][n] = 1;
                return A[m][n];
            }
            A[m][n] = _uniquePathsWithObstacles(m-1, n, A, obstacleGrid) + _uniquePathsWithObstacles(m, n-1, A, obstacleGrid);
            return A[m][n];
        }

        int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
            vector<vector<int> > A;
            int m = obstacleGrid.size();
            int n;
            if (m >= 1)
                n = obstacleGrid[0].size();
            for (int i = 0; i <= m; i++) {
                vector<int> t(n+1, 0);
                A.push_back(t);
            }
            _uniquePathsWithObstacles(m, n, A, obstacleGrid);

            return A[m][n];
        }
        
        /*
        int _uniquePathsWithObstacles(int m, int n, vector<vector<int> > &A) {
            if (A[m][n] != 0) return A[m][n];
            if (m == 1 || n == 1) {
                A[m][n] = 1;
                return A[m][n];
            }
            A[m][n] = _uniquePathsWithObstacles(m-1, n, A) + _uniquePathsWithObstacles(m, n-1, A);
            return A[m][n];
        }

        int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
            vector<vector<int> > A;
            int m = obstacleGrid.size();
            int n;
            if (m >= 1)
                n = obstacleGrid[0].size();
            for (int i = 0; i <= m; i++) {
                vector<int> t(n+1, 0);
                A.push_back(t);
            }
            for (int i = 1; i <= m;i ++)
                A[i][1] = 1;
            for (int i = 1; i <= n;i ++)
                A[1][i] = 1;
            _uniquePathsWithObstacles(m, n, A);

            for (int i = 1; i <= m; i ++)
                for (int j = 1; j <= n; j++)
                    if (obstacleGrid[i-1][j-1] == 1)
                        A[m][n] -= A[i][j] * A[m-i+1][n-j+1];
            return A[m][n];
        }
        
         */

};

int main()
{
    Solution S;
/*    for (int i = 1; i <= 5; i ++)
        for (int j = 1; j <= 8; j++)
            cout << "uniquePaths["<<i<<"]["<<j <<"] :is " << S.uniquePaths(i, j)<<endl;
*/
    vector<vector<int> >A;
    vector<int> x;
    x.push_back(0);
    x.push_back(1);
    A.push_back(x);
    cout << "uniquePaths "<<S.uniquePathsWithObstacles(A)<<endl;

    return 0;
}
