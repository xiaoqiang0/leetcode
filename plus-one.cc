#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
    public:
        vector<int> plusOne(vector<int> &digits) {
            
            int n = digits.size();
            int i;
            if (n == 0) {
                digits.push_back(1);
                return digits;
            }
            for (i = n - 1; i >= 0; i --)
                if (digits[i] == 9)
                    digits[i] = 0;
                else {
                    digits[i]++;
                    return digits;
                }
            if (i == -1)
                digits.insert(digits.begin(), 1);

            return digits;

        }
};


int main()
{
    //int a[] = {1,1,2,3};
    //int a[] = {9,9,9,9};
    //int a[] = {9,9,9,8};
    int a[] = {};

    vector<int> v;
    v.assign(a, a + sizeof(a)/sizeof(int));

    Solution S;
    v = S.plusOne(v);

    for (int i = 0; i < v.size();i++)
        cout <<v[i]<<" ";
    cout <<endl;

    return 0;

}
