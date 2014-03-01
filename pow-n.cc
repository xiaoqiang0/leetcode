#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <limits>

using namespace std;

class Solution {
    public:
        double pow(double x, int n) {
            double res = 1;
            int flag = 1;
            int div = 0;
            if (x == 0) return 0;
            if (n == 0) return 1;

            if (n < 0) {
                div = 1;
                n = -n;
            }

            if (x < 0) {
                if (n % 2 == 0 || (-n) % 2 == 0)
                    flag = 1;
                else
                    flag = -1;
                x = -x;
            }

            if (x == 1)
                return flag;

            if (x == 1) return 1;


            for (int i = 0; i < n; i++){
                res = res*x;
                if (res == 0)
                    return 0;
                if (res == std::numeric_limits<double>::max())
                    break;
                if (res == std::numeric_limits<double>::min())
                    break;
            }

            if (div) {
                if (res == std::numeric_limits<double>::max())
                    return std::numeric_limits<double>::min();
                else if (res == std::numeric_limits<double>::min())
                    return std::numeric_limits<double>::max(); 
                else 
                    res = 1 / res;
            }

            res = res * flag;

            return res;
        }
};


int main()
{
    Solution S;
    cout << S.pow(2, 100000)<<endl;
    cout << S.pow(2, -100000)<<endl;
    cout << S.pow(0.00001, 2147483647)<<endl;
    cout << S.pow(8.88023, 3)<<endl;
}
