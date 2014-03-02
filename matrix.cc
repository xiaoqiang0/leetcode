#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;
class Solution {
    public:
        /*
           You are given an n x n 2D matrix representing an image.
           Rotate the image by 90 degrees (clockwise).
         */
        void rotate(vector<vector<int> > &matrix) {
            int N = matrix.size();

            for (int i = 0; i < N/2; i++) {
                for (int j = i; j < N - i - 1; j++) {
                    /*
                       (i,j)  -> (N-1-j, i)
                       -> (n-1-i, n-1-j)
                       -> (j, n-1-i)
                     */
                    int t;
                    t = matrix[i][j];

                    matrix[i][j] = matrix[N-1-j][i];
                    matrix[N-1-j][i] = matrix[N-1-i][N-1-j];
                    matrix[N-1-i][N-1-j] = matrix[j][N-1-i];
                    matrix[j][N-1-i] = t;
                }
            }
        }

        bool searchMatrix(vector<vector<int> > &matrix, int target) {
            int m = matrix.size();
            int n;

            if (m > 0)
                n = matrix[0].size();
            else
                return false;
            if (n == 0)
                return false;
            int k = -1;
            int l = 0, u = m - 1;
            k = 0;
            while (l <  u){
                int mid = (l + u) / 2;

                if (matrix[mid][0] > target){
                    u = mid - 1;
                    k = mid - 1;
                    if (k < 0) return false;
                } else if (matrix[mid][0] < target) {
                    if (matrix[mid][n-1] >= target) {
                        u = l;
                        k = mid;
                        break;
                    } else {
                        l = mid + 1;
                        k = l;
                        if (k >= m) return false;
                    }
                } else 
                    return true;

            }

            l = 0; u = n -1;
            while(l <= u){
                int mid = (l + u) / 2;
                if (matrix[k][mid] > target)
                    u = mid - 1;
                else if (matrix[k][mid] < target)
                    l = mid + 1;
                else 
                    return true;
            }

            return false;
        }
        void setZeroes(vector<vector<int> > &matrix) {
            int m = matrix.size();
            int n;

#define MAX_TAG 123454321

            if (m > 0)
                n = matrix[0].size();
            else
                return;

            if (n == 0)
                return;
            for (int i = 0; i < m; i ++)
                for (int j = 0; j < n; j++) {
                    if (matrix[i][j] == 0) {
                        matrix[i][j] = MAX_TAG;
                        for (int k = 0; k < m; k ++)
                            if (matrix[k][j] != 0)
                                matrix[k][j] = MAX_TAG;
                        for (int k = 0; k < n; k ++)
                            if (matrix[i][k] != 0)
                                matrix[i][k] = MAX_TAG;
                    }
                }

            for (int i = 0; i < m; i ++)
                for (int j = 0; j < n; j++) {
                    if (matrix[i][j] == MAX_TAG) {
                        matrix[i][j] = 0;
                    }
                }

        }


        int C(int n, int k)
        {
            if (n == 0 || n == 1) return 1;
            if (k == 0 || k == n) return 1;

            if (n-k < k) k = n-k;
            long m = 1;
            for (int i = n - k + 1; i <= n; i++)
                m *= i;
            for (int i = 1; i <= k; i++)
                m /= i;

            return m;

        }

        vector<vector<int> > generate (int numRows) {
            vector<vector<int> >  res;

            if (numRows == 0) return res;
            if (numRows == 1) {
                vector<int> r;
                r.push_back(1);
                res.push_back(r);
                return res;
            }

            for (int i = 0; i < numRows; i++) {
                vector<int> r;
                int t = 1;
                r.push_back(1);
                if (i == 0) {
                    res.push_back(r);
                    continue;
                }

                for (int j = 1; j < i; j++) {
                    t = t*(i - j + 1) / j;
                    r.push_back(t);
                }
                r.push_back(1);
                res.push_back(r);
            }

            return res;
        }
        vector<int> getRow(int rowIndex) {
            vector<int> r;
            int t = 1;
            r.push_back(1);
            if (rowIndex == 0 || rowIndex == 1) {
                vector<int> r;
                r.push_back(1);
                return r;
            } 
            for (int j = 1; j < rowIndex; j++) {
                t = t*(rowIndex - j + 1) / j;
                r.push_back(t);
                cout << t << " ";
            }
            r.push_back(1);
            return r;
        }


        vector<vector<int> > generateMatrix(int n) {
            vector<vector<int> > res(n, vector<int>(n, 0));
            int k = 1;
            int i=0,j=0;
            int d = 0;

            while (k <= n*n){
                res[i][j] = k;

                switch (d){
                    case 0:
                        if (j == n-1 || res[i][j+1] != 0) {
                            d = 1;
                            i++;
                        } else {
                            j++;
                        }
                        break;

                    case 1:
                        if (i == n-1 || res[i+1][j] != 0) {
                            d = 2;
                            j--;
                        } else {
                            i++;
                        }
                        break;
                    case 2:
                        if (j == 0||res[i][j-1] != 0) {
                            d = 3;
                            i--;
                        } else {
                            j--;
                        }
                        break;
                    case 3:
                        if (i == 0 || res[i-1][j] != 0) {
                            d = 0;
                            j++;
                        } else {
                            i--;
                        }
                        break;
                }
                k++;
            }


            return res;
        }
};

int main()
{

    vector<vector<int> > m;
    vector<int> p1, p2, p3;
    p1.push_back(0);
    p1.push_back(1);
    /*
       p1.push_back(3);
       p2.push_back(3);
       p2.push_back(5);
       p2.push_back(6);
       p3.push_back(7);
       p3.push_back(8);
       p3.push_back(9);
     */
    m.push_back(p1);
    /*
       m.push_back(p2);
       m.push_back(p3);
     */
    Solution S;


    //   S.setZeroes(m);
    //   S.generate(5);
    S.getRow(3);
    /*
       S.rotate(m);
       if (S.searchMatrix(m, 1))
       cout <<"Exist " <<endl;

     */
    m = S.generateMatrix(2);
    cout <<"----rotated Matrix:" <<endl;

    for (int i = 0; i < 2; i++){
        for (int j=0; j < 2; j++)
            cout <<m[i][j];
        cout <<endl;
    }
    cout <<endl;

    return 0;
}
