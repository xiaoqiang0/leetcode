#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <limits>
#include <queue>
#include <map>

using namespace std;
class Solution {
    public:
        int firstMissingPositive(int A[], int n) {
            vector<int> v(n+1, 0);

            for (int i = 0; i < n; i ++){
                if (A[i] < 0 || A[i] > n) continue;
                v[A[i]] = 1;
            }

            for (int i = 1; i <=n ; i++)
                if (v[i] == 0)
                    return i;
        }
};
int main()
{
    int A[] = {3,4,1, -1};
    //int A[] = {1,2,0};
    Solution S;
    cout << S.firstMissingPositive(A, sizeof(A)/sizeof(int)) <<endl;;
    return 0;
}
