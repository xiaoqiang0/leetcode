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
};
int main()
{
    //int A[] = {2,3,1,1,4};
    //int A[] = {3,2,1,0,4};
    int A[] = {2,0};

    Solution S;

    if (S.canJump(A, sizeof(A)/sizeof(int)))
        cout << "Can jump" <<endl;
    else
        cout << "Can not jump" <<endl;


    return 0;
}

