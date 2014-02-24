#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
    public:
        int searchInsert(int A[], int n, int target) {
            int i;
            for (i = 0; i < n; i++)
                if (A[i] == target) return i;
                else if (A[i] > target) return i;

            return i;
        }
        int removeElement(int A[], int n, int elem) {
            int i = -1, j = 0;
            if (n == 0) return n;
            for (;j < n; j++){
                if (A[j] == elem) continue;

                A[++i] = A[j];
            }

            return i+1;
            
        }

        int removeDuplicates(int A[], int n) {
            int i = 0, j = 0;
            if (n == 0) return 0;
            for (j = 1;j < n; j++){
                if (A[i] == A[j]) continue;

                A[++i] = A[j];
            }

            return i+1;
            
        }

        void merge(int A[], int m, int B[], int n) {
            int i, j, k;

            k = m + n - 1;
            i = m - 1;
            j = n - 1;

            while (1) {
                if (i < 0 || j < 0)
                    break;
                if (A[i] >= B[j])
                    A[k--] = A[i--];
                else
                    A[k--] = B[j--];
            }

            while (i>=0) {
                A[k--] = A[i--];
            }
            while (j>=0) {
                A[k--] = B[j--];
            }

        }


        void sortColors(int A[], int n) {
            int i, j;
            j = 0;
            for (i = 0; i < n; i++){
                if (A[i] == 0) {
                    int t = A[j];
                    A[j] = A[i];
                    A[i] = t;
                    j++;
                }
            }
            j = n-1;
            for (i = n-1; i >= 0; i--){
                if (A[i] == 0) break;
                if (A[i] == 2) {
                    int t = A[j];
                    A[j] = A[i];
                    A[i] = t;
                    j--;
                }
            }

        }
};

int main()
{
    int A[8] = {1,3,4,5, 8};
    int B[3] = {2, 6, 7};
    int C[5] = {1,0,2,2,1};
    Solution S;

    cout << "New length: " << S.removeElement(A, 1, 1) <<endl;
    cout << "New length: " << S.removeDuplicates(A, 6) <<endl;

    S.merge(A, 5, B, 3);

    for (int i = 0; i < 8; i ++)
        cout <<A[i] << " ";

    cout <<endl;
    S.sortColors(C, 5);

    for (int i = 0; i < 5 ; i++)
        cout <<C[i] <<" ";
    cout <<endl;

    return 0;
}
