#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
    public:
        int C(int n, int m, int t) {
            int mul = 1;
            for (int i = m > t ? m + 1 : t + 1; i <= n; i++) {
                mul *= i;
            } for (int i = t > m ? m : t; i >= 1; i--)
            mul /= i;

            return mul;
        }

        int climbStairs1(int n) {
            int i = 0;
            long int sum = 0;
            for (i = 0; i < n; i++) {
                if (n - i * 2 < 0)
                    break;
                sum += C(n - i, i, n - i * 2);
            }

            return sum;
        }

        int climbStairs(int n) {
            int a = 0, b = 1, t = 0;
            for (int i = 0; i < n; i++) {
                t = b;
                b =  a + b;
                a = t;
            }
            return b;
        }

};

int main()
{
    Solution S;
    cout << "climbStairs Expected(2): " << S.climbStairs(2) << endl;
    cout << "climbStairs Expected(21): " << S.climbStairs(7) << endl;
    cout << "climbStairs Expected(34): " << S.climbStairs(8) << endl;
    cout << "climbStairs Expected(55): " << S.climbStairs(9) << endl;
    cout << "climbStairs Expected(89): " << S.climbStairs(10) << endl;
    cout << "climbStairs Expected(14930352): " << S.
        climbStairs(35) << endl;

    return 0;
}
