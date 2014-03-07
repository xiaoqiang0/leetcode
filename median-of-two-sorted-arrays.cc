#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <limits>

using namespace std;
class Solution {
    public:
        double findMedianSortedArrays(int A[], int m, int B[], int n) {
            int i,j, k;
            int ret, ret1;
            
            if (m == 0 && n == 0)
                return -1;

            if ((m+n) % 2 == 0){
                k = (m+n)/2;
            } else {
                k = (m+n)/2+1;
            }


            if (m == 0) {
                if (n%2 == 1)
                    return B[n/2];
                else
                    return 1.0*(B[n/2-1]+B[n/2])/2.0;
            }
            if (n == 0){
                if (m%2 == 1)
                    return A[m/2];
                else
                    return 1.0*(A[m/2-1]+A[m/2])/2.0;
            }

            i = 0; j = 0;


            while (k && i < m && j < n) {
                if (A[i] < B[j]) {
                    ret = A[i];
                    i++;
                } else {
                    ret = B[j];
                    j++;
                }

                k--;
            }

            if (k > 0) {
                if (i<m) {
                    while (k) {
                        ret = A[i];
                        k--;
                        i++;
                    }
                } else {
                    while (k) {
                        ret = B[j];
                        k--;
                        j++;
                    }
                }
            }

            if (i < m && j < n) {
                if (A[i] < B[j])
                    ret1 = A[i];
                else
                    ret1 = B[j];
            } else if (i<m) {
                ret1 = A[i];
            } else if (j<n){
                ret1 = B[j];
            }

            if ((m+n) % 2 == 0)
                return 1.0*(ret1 + ret)/2;
            else
                return ret;
        }
};

int main()
{
    //int A[] = {1,2,3,4,5};
    //int B[] = {6,7,8,9,10,11,12};
    int A[] = {1};
    int B[] = {2,3,4};
    Solution S;

    cout << "MID:" << S.findMedianSortedArrays(A, sizeof(A)/sizeof(int), B, sizeof(B)/sizeof(int))<<endl;

    return 0;
}
