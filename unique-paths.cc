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
        
        int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
            int m = obstacleGrid.size();
            int n;

            if (m >= 1)
                n = obstacleGrid[0].size();
            else
                return 0;

            if (n == 0) return 0;

            vector<vector<int> > A(m, vector<int>(n, 0));

            if (obstacleGrid[0][0] == 1) return 0;

            A[0][0] = 1;
            for (int i = 0; i < m; i++)
                for (int j = 0; j < n; j++) {
                    if (i == 0 && j == 0) continue;
                    if (obstacleGrid[i][j] == 1){
                        A[i][j] = 0;
                        continue;
                    }

                    if (i == 0)
                        A[i][j] = A[i][j-1];
                    else if (j == 0)
                        A[i][j] = A[i-1][j];
                    else 
                        A[i][j] = A[i][j-1] + A[i-1][j];
                }
                    

            return A[m-1][n-1];
        }
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
