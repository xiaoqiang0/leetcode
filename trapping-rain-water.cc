#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

struct Pot{
    int idx;
    int val;

    Pot(int i, int v): idx(i), val(v){}
};
class Solution {
    public:
        
        int trap(int A[], int n) {
            vector<Pot> S;
            int low = 0;
            int sum = 0;
            if (n <= 2) return 0;
            S.push_back(Pot(0, A[0]));
            low = A[0];
            for (int i = 0; i < n-1; i ++){
                //找到一个下降区间的最低点
                if (S.empty()|| A[i+1] < A[i]){
                    S.push_back(Pot(i+1, A[i+1]));
                    low = A[i+1];
                    continue;
                }
                //A[i+1] > S.top();
                //(min(A[i+1], S.top) - low ) * (A[i+1] - S.top - 1)
                Pot cur = S[S.size() - 1];
                if (A[i+1] < cur.val){
                    sum += (A[i+1] - low) * (i + 1 - cur.idx - 1);
                    cout <<"Add: (" << cur.idx<< "," << i+1 << ") low:" << low<< ", plus: " << (A[i+1] - low) * (i + 1 - cur.idx - 1)  <<endl;
                    low = A[i+1];
                } else {
                    sum += (cur.val - low) * (i+1 - cur.idx - 1);
                    cout <<"-Add: (" << cur.idx<< "," << i+1 << ") low:" << low<< ", plus: " << (cur.val - low) * (i+1 - cur.idx - 1) <<endl;
                    low = cur.val;

                    //Pop stack find another lower than A[i+1] in the stack
                    S.pop_back();
                    if (A[i+1] > cur.val){
                        i--;
                        continue;
                    }
                }
                // Don't missing i+1 if i+2 lower than it.
                if (i+2 <= n -1 && A[i+2] < A[i+1]) {
                    S.push_back(Pot(i+1, A[i+1]));
                }
            }

            return sum;
        }
};

int main()
{
    //int a[] = {1,3,6,3,1,2,4};
    //int a[] = {6,3,1,2,4, 5};
    //int a[] = {5,2,1,2,1, 5};
    int a[] = {4,2,0,3,2,5};
    vector<int >v;
    v.assign(a, a + sizeof(a)/sizeof(int));
    Solution S;
    cout << S.trap(a, sizeof(a)/sizeof(int))<<endl;
        
    return 0;
}
