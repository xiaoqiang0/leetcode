#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <limits>

using namespace std;

struct Q{
    int x;
    int y;
    Q(int x, int y):x(x), y(y) {}
};
class Solution {
    public:
        void gen(vector<string> & A, int n, vector<vector<string> > &res, vector<Q> &Queens)
        {
            if (n == A.size()){
                res.push_back(A);
                return ;
            }

            for (int i = 0; i < A.size(); i++){
                //set A[n][i];
                int skip = 0;
                for (int j = 0; j < Queens.size(); j++){
                    Q t = Queens[j];

                    if (t.x == n || t.y == i || (abs(t.x - n) == abs(t.y - i))){
                        skip = 1;
                        break;
                    }
                }
                if (skip == 0){
                    A[n][i] = 'Q';
                    Queens.push_back(Q(n,i));
                    gen(A, n+1, res, Queens);
                    Queens.pop_back();
                    A[n][i] = '.';
                }
            }
        }
        vector<vector<string> > solveNQueens(int n) {
            vector<vector<string> > res;
            vector <string> init(n, string(n, '.'));
            vector<Q> Queens;
            gen(init, 0, res, Queens);
            return res;
        }
};
int main()
{
    Solution S;
    vector<vector<string> > res;
    res = S.solveNQueens(0);
    for (int i = 0; i < res.size(); i ++){
        for (int j = 0; j < res[i].size(); j++)
            cout <<res[i][j]<<endl;

        cout <<endl;
    }

    return 0;
}


