#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <limits>

using namespace std;


class Solution {
    public:
        int sqrt(int x) {
            if (x == 0) return 0;
            long long u = x/2+1, l = 0;

            while (l <= u){
                long long mid = (l+u)/2;
                long long t = mid*mid;
                cout <<l<<endl;
                if (t == x) return mid;

                if (t < x)
                    l = mid+1;
                else
                    u = mid-1;
            }

            return u;
        }
        int sqrt(int x) {
            long long i = 0;
            long long j = x / 2 + 1;
            while (i <= j)
            {
                long long mid = (i + j) / 2;
                long long sq = mid * mid;
                if (sq == x) return mid;
                else if (sq < x) i = mid + 1;
                else j = mid - 1;
            }
            return j;
        }
};
int main()
{
    Solution S;

    cout << S.sqrt(2147483647) <<endl;
    return 0;
}
