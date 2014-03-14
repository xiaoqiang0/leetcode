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
        vector<int> searchRange(int A[], int n, int target) {
            int l = 0, u = n-1;
            vector<int> res(2, -1);
            while (l < u){
                int k = (l+u)/2;

                if (A[k] < target)
                    l = k+1;
                else if (A[k] > target)
                    u = k-1;
                else {
                    int left = k, right = k;

                    while (left > 0 && A[left-1] == target){
                        left--;
                    }
                    while (right < (n-1) && A[right+1] == target){
                        right++;
                    }

                    res[0] = left;
                    res[1] = right;
                    return res;
                }
            }

            if (A[l] >= target && l < n-1) {
                if (A[l] <= target && target <= A[l+1]) {
                    res[0] = l;
                    if (A[l] == target && A[l+1] != target)
                        res[1] = l;
                    else
                        res[1] = l+1;
                }
            } else if (A[l] < target && l > 0){
                if (A[l-1] >= target && A[l] <= target) {
                    res[0] = l-1;
                    res[1] = l;
                }
            } else if (A[l] == target) {
                res[0] = res[1] = l;
            }
            
            return res;
        }
};
int main()
{
    //int A[] = {5, 7, 7, 8, 8, 10};
    //int A[] = {2,2};
    int A[] = {1,4};
    //int A[] = {1,2,3}; //2

    Solution S;
    vector<int > res = S.searchRange(A, sizeof(A)/sizeof(int), 1); // 3, 4;
    
    cout << res[0]<< ","<<res[1] <<endl;

    return 0;
}
