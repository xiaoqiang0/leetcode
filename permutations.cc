#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <limits>
#include <string>
using namespace std;

class Solution {
    public:

        void swap(vector<int > &A, int i, int j)
        {
            int t = A[i];
            A[i] = A[j];
            A[j] = t;
        }
        void gen(vector<int > &A, int m, vector<vector <int> > &res)
        {
            int n = A.size();
            if  (n == m + 1){
                res.push_back(A);
            }else{
                int j;
                for (j = m; j < n; j++){
                    swap(A,m,j);
                    gen(A,m + 1, res);
                    swap(A,m,j);
                }
            }
        }
        vector<vector<int> > permute(vector<int> &num) {
            vector<vector<int> >  res;
            gen(num, 0, res);

            return res;
        }
};

int main()
{
    int num = 3;
    Solution S;
    vector<int> A(num, 0);
    for (int i = 0 ; i < num; i ++)
        A[i] = i+1;
    vector<vector<int> > res = S.permute(A);

    for (int i = 0; i < res.size(); i++){
        for (int j = 0; j < res[i].size(); j++)
            cout <<res[i][j];
        cout <<endl;
    }

    return 0;
}
