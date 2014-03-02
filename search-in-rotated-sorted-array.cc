#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
    public:
        int search_1(int A[], int n, int target) {

            int l, u;
            l = 0, u = n-1;

            while (l <= u) {
                int k = (l+u)/2;

                if (A[k] == target) return k;

                if (A[l] < A[k]){
                    if (target >= A[l] && target < A[k])
                        u = k-1;
                    else
                        l = k + 1;
                } else if (A[l] == A[k]) {
                    if (A[l] == target)
                        return l;
                    else if (A[u] == target)
                        return u;
                    else
                        return -1;
                } else {
                    if (target > A[k] && target <= A[u])
                        l = k+1;
                    else
                        u = k - 1;
                }
            }
            return -1;
        }
        bool search(int A[], int n, int target) {
            int l, u;
            l = 0, u = n-1;

            while (l <= u) {
                int k = (l+u)/2;

                if (A[k] == target) return true;

                if (A[l] < A[k]){
                    if (target >= A[l] && target < A[k])
                        u = k-1;
                    else
                        l = k + 1;
                } else if (A[l] == A[k]) {
                    if (A[l] == target)
                        return true;
                    else if (A[u] == target)
                        return true;
                    //111113111111111111111, find 3
                    if (A[l] == A[k] && A[k] == A[u]){
                        l ++;
                        u --;
                    } else 
                        l = k + 1;
                } else {
                    if (target > A[k] && target <= A[u])
                        l = k+1;
                    else
                        u = k - 1;
                }
            }
            return false;
        }
};
int main()
{
    //int A[] = {4,5,6,7,0,1,2};
    //int A[] = {1,1,3,1};
    int A[] = {1,3,1,1,1};
    Solution S;

    if (S.search(A, sizeof(A)/ sizeof(int), 3))
        cout << "Exist" <<endl;
    return 0;
}
