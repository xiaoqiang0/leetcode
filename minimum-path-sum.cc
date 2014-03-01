#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
    public:
        int minPathSum(vector<vector<int> > &grid) {
            int m = grid.size();
            int n;

            if (m == 0) return 0;
            n = grid[0].size();
            if (n == 0) return 0;
            vector<vector<int> > d(m, vector<int>(n));
            d[0][0] = grid[0][0];
            for (int i = 0; i < m; i ++){
                for (int j = 0; j < n; j ++){
                    int top = -1, left = -1;

                    if (i - 1 >= 0) top = d[i-1][j];
                    if (j - 1 >= 0) left = d[i][j-1];

                    if (top == -1 && left == -1)
                        d[i][j] = grid[i][j];
                    else if (top == -1)
                        d[i][j] = grid[i][j] + left;
                    else if (left == -1)
                        d[i][j] = grid[i][j] + top;
                    else 
                        d[i][j] =grid[i][j] + (top > left ? left: top);

 //                   cout <<d[i][j] << " ";
                }
 //               cout <<endl;
            }
            
            return d[m-1][n-1];
        }
};


int main()
{
    //int a[] = {1,1,2,3};
    //int a[] = {9,9,9,9};
    //int a[] = {9,9,9,8};
    int a[] = {};
    vector<vector<int> > g(4, vector<int>(3));
    g[0][0] = 1;g[0][1] = 1;g[0][2] = 1;
    g[1][0] = 3;g[1][1] = 2;g[1][2] = 1;
    g[2][0] = 4;g[2][1] = 6;g[2][2] = 1;
    g[3][0] = 5;g[3][1] = 1;g[3][2] = 1;



    Solution S;

    cout <<S.minPathSum(g) <<endl;

    return 0;

}

