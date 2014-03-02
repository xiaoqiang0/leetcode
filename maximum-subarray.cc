#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
    public:
        int maxSubArray(int A[], int n) {
            int max;
            int cur_max;

            if (n == 0) return 0;
            if (n == 1) return A[0];
            max = A[0]; 
            cur_max = 0;
            for (int i = 0; i < n; i++){
                if (cur_max > 0)
                    cur_max = A[i] + cur_max;
                else
                    cur_max = A[i];

                if (cur_max > max)
                    max = cur_max;
            }

            return max;
        }
};

int main()
{
    //int A[] = {-2, 1, -3, 4, -1 , 2, 1, -5, 4};
    int A[] = {-1};
    Solution S;
    cout << S.maxSubArray(A, sizeof (A) / sizeof(int)) <<endl;

    return 0;
}
