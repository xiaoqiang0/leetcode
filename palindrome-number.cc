#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;
class Solution {
    public:
        bool isPalindrome(int x) {
            if (x < 0) return false;

            int t = 0;
            int s = x;
            while (x){
                
                t = 10*t + (x % 10);
                x = x / 10;
            }

           return s == t;

        }
};
int main()
{
    Solution S;

    cout << "121" << S.isPalindrome(121)<<endl;
    cout << "1121" << S.isPalindrome(1121)<<endl;
    return 0;
}
