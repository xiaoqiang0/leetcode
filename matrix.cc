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
};

int main()
{

    vector<vector<int> > m;
    vector<int> p1, p2, p3;
    p1.push_back(1);
    p1.push_back(2);
    p1.push_back(3);
    p2.push_back(4);
    p2.push_back(5);
    p2.push_back(6);
    p3.push_back(7);
    p3.push_back(8);
    p3.push_back(9);

    m.push_back(p1);
    m.push_back(p2);
    m.push_back(p3);

    Solution S;
    S.rotate(m);

    cout <<"rotated Matrix:" <<endl;

    for (int i = 0; i < 3; i++){
        for (int j=0; j < 3; j++)
            cout <<m[i][j];
        cout <<endl;
    }

    cout <<endl;

    return 0;
}
