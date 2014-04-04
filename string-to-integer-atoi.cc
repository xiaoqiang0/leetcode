#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <limits>
#include <queue>
#include <map>

using namespace std;
class Solution {
    public:
        int atoi(const char *str) {
            const char *p = str;
            int flag = 1;
            if (str == NULL) return 0;

            while (*p == ' ') p++;

            if (*p == '-') { flag = -1; p++; }
            else if (*p == '+') p++;
            int ret = 0;
            int k = 1;
            while (*p && *p != ' ') {
                if (*p >= '0' && *p <= '9') {
                    int cur = ret * 10 + *p - '0';
                    if (flag == 1) {
                        if (ret > numeric_limits<int>::max() / 10 || \
                           (ret == numeric_limits<int>::max() / 10 && *p - '0' > 7))
                            return  numeric_limits<int>::max();
                    } else {
                        if (ret > numeric_limits<int>::max() / 10 || \
                           (ret == numeric_limits<int>::max() / 10 && *p - '0' > 8))
                            return  numeric_limits<int>::min();
                    }
                    
                    ret = cur;
                } else
                    break;
            
                p++;
            }

            
            return ret * flag;

        }
};
int main()
{
    Solution S;
    cout << S.atoi("  10522545459") <<endl;
    return 0;
}
