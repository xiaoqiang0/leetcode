#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <limits>

using namespace std;
class Solution {
    public:
        bool canJump(int A[], int n) {

            if (n == 0) return false;
            if (n == 1) return true;

            for (int i = 0 ; i < n;){
                int k = A[i];

                if (k == 0 && i < n-1) return false;
                i = i+k;

                if (i >= n-1)
                    return true;
            }

            return false;
        }
        int compute(int A[], int i, vector<int> &v)
        {
            if (i == 0){
                v[i] = 0;
            }
            if (v[i] != -1) return v[i];
            int min = 1000000;
            for (int j = i-1; j >= 0; j--) {
                int t = compute(A, j, v);
                if (A[j] >= i-j && min > t+1)
                    min = t + 1;
            }
            v[i] = min;
            return min;
        }

        int jump(int A[], int n) {
            vector<int> v(n+1, 100000);
            if (n == 0) return 0;
            
            v[0] = 0;
            for (int i = 0; i < n; i++) {
                int k = A[i];
                if (i>0 && k <= (A[i-1] - 1))
                    continue;
                if (i+k >=n)
                    k = n-i - 1;
                while (k && (i+k) < n){
                    if (v[i+k] > v[i] + 1)
                        v[i+k] = v[i]+1;
                    k--;
                }
            }

            return v[n-1];
        }
};
int main()
{
    //int A[] = {2,3,1,1,4};
    //int A[] = {3,2,1,0,4};
    int A[] = {2,1};
    Solution S;
/*
    if (S.canJump(A, sizeof(A)/sizeof(int)))
        cout << "Can jump" <<endl;
    else
        cout << "Can not jump" <<endl;
*/
    cout << "steps:" <<S.jump(A, sizeof(A)/sizeof(int))<<endl;

    return 0;
}

