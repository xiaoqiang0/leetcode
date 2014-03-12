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

            long long ds = divisor, dd = dividend;
            if (divisor < 0) ds = 0-ds;
            if (dividend< 0) dd = 0-dd;
            
            long long int d = ds;
            int w = 0;
            while (d <= dd){
                d <<= 1;
                w++;
            }
            
            d >>= 1;
            int start = w - 1;
            while(dd >= ds){
                long long x = d;
                
                if (x <= dd) {
                    k += 1<<start;
                    dd -= x;
                }
                d >>= 1;
                start--; 
            }

            return k*flag;
        }
};
int main()
{
    Solution S;

    cout <<S.divide(1, -1)<<endl;
    cout <<S.divide(1010369383, 2147483648)<<endl;
    cout <<S.divide(100, 3)<<endl;

    return 0;
}
