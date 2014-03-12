#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <limits>

using namespace std;

class Solution {
    public:
        int divide(int dividend, int divisor) {
            if (dividend == 0) return 0;
            if (divisor == 0) {
                if (dividend > 0)
                    return std::numeric_limits<int>::max();
                else
                    return std::numeric_limits<int>::min();
            }

            if (divisor == 1) return dividend;
            int k = 0;
            int flag = 0;


            if ((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0))
                flag = 1;
            else
                flag = -1;

            if (divisor < 0) divisor = -divisor;
            if (dividend< 0) dividend= -dividend;

            while ((divisor & 0x1) == 0) {
                divisor >>= 1;
                dividend>>= 1;
            }

            if (divisor != 1) {
                while (dividend > 0){
                    if (dividend - divisor >= 0){
                        k++;
                        dividend = dividend-divisor;
                    }else
                        break;
                }
            } else
                k = dividend;

            return k*flag;
        }
};
int main()
{
    Solution S;

    cout <<S.divide(2147483647, 2)<<endl;

    return 0;
}
