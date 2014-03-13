#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <limits>
#include <string>
#include <set>

using namespace std;

class Solution {
    public:

        void swap(vector<int > &A, int i, int j)
        {
            int t = A[i];
            A[i] = A[j];
            A[j] = t;
        }
        void gen(vector<int > &A, int m, set<vector <int> > &res)
        {
            int n = A.size();
            if  (n == m + 1){
                res.insert(A);
            }else{
                int j;
                for (j = m; j < n; j++){
                    if (j > m && A[j] == A[j-1])
                        continue;
                    swap(A,m,j);
                    gen(A,m + 1, res);
                    swap(A,m,j);
                }
            }
        }
        vector<vector<int> > permute(vector<int> &num) {
            vector<vector<int> >  res;
            set<vector<int> >  r;
            gen(num, 0, r);
            res.assign(r.begin(), r.end());
            return res;
        }
        vector<vector<int> > permuteUnique(vector<int> &num) {
            vector<vector<int> >  res;
            set<vector<int> >  r;
            gen(num, 0, r);
            res.assign(r.begin(), r.end());

            return res;

        }
        string getPermutation1(int n, int k) {
            vector<int> A(n, 0);
            for (int i = 0 ; i < n; i ++)
                A[i] = i+1;
            vector<vector<int> > res = permute(A);

            string r;

            for (int i = 0; i < n; i ++)
                r.append(to_string(res[k-1][i]));

            return r;
        }


        string getPermutation(int n, int k) {
            vector<int> A(n, 0);
            for (int i = 0 ; i < n; i ++)
                A[i] = i+1;
            k--;           
            string r;
            int total = 1;
            for (int i = 1; i <= n; i ++)
                total *= i;
            for (int i = 0; i < n; i ++) {
                //i
                //total/n
                total /= n-i;
                int idx = k / total;

                r.append(to_string(A[idx]));
                for (int j = idx + 1; j < n - i; j++)
                    A[j-1] = A[j];
                k = k % total;
            }

            return r;
        }
        void reverse(vector<int> &num, int i)
        {
            for (int k = 0; k < (num.size() - i)/2; k++){
                int t = num[k+i];
                num[k+i] = num[num.size()-k-1];
                num[num.size()-k-1] = t;
            }
        }
        void nextPermutation(vector<int> &num) {

            int i = -1, j = -1;
            if (num.size() == 1) return;

            for (int k = 1; k < num.size(); k++){
                if (num[k-1] < num[k] && i<k)
                    i = k;
            }
            if (i == -1) {
                reverse(num, 0);
                return ;
            }
            for (int k = 0; k < num.size(); k++){
                if (num[i-1] < num[k] && j<k)
                    j = k;
            }

            if (i == -1||j == -1)
                return;
            int t = num[i-1];
            num[i-1] = num[j];
            num[j] = t;

            reverse(num, i);

            return ;
        }
};

int main()
{
    int num = 3;
    int x[] = {3,3,0,0,2,3,2};
    Solution S;
    vector<int> A;
    for (int i = 0 ; i < sizeof(x)/sizeof(int); i ++)
        A.push_back(x[i]);
    vector<vector<int> > res = S.permuteUnique(A);
    for (int i = 0; i < res.size(); i++){
        for (int j = 0; j < res[i].size(); j++)
            cout <<res[i][j];
        cout <<endl;
    }
    cout <<endl;
    /*
       for (int i = 1; i <= 6; i++)
       cout <<S.getPermutation(3, i) <<endl;
       S.nextPermutation(A);

       for (int i = 0 ; i < num; i ++)
       cout <<A[i];
       cout <<endl;
     */

    return 0;
}
