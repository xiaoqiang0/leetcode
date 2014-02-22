#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;
class Solution {
    public:
        int reverse(int x) {
            string s;
            int flag = 0;
            if (x < 0){
                flag = 1;
                x = 0 - x;
            }

            while (x) {
                int i = x % 10;
                s.append(1, i + 48);
                x = x / 10;
            }

            return flag == 1 ? 0 - atoi(s.c_str()): atoi(s.c_str());
        }
};

int main()
{
    int n = 123;

    Solution S;
    

    cout << S.reverse(-123) <<endl;
    return 0;
}
