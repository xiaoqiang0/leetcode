#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <limits>
#include <string>

using namespace std;
class Solution {
    public:
        bool isPalindrome(string s) {
            
            if (s.length() == 0)
                return true;

            std::transform(s.begin(), s.end(),s.begin(), ::toupper);

            string orig;
            

            for (int i = 0; i < s.length(); i++) {
                if ((s[i] >= 'A' && s[i] <= 'Z')||(s[i] >= '0' && s[i] <= '9'))
                    orig += s[i];
            }

            string new_str = orig;
            
            //cout <<orig <<endl;
            for (int i = 0; i < new_str.length()/2; i ++){
                char c = new_str[i];
                new_str[i] = new_str[new_str.length() - 1 - i];
                new_str[new_str.length() - 1 - i] = c;
            }

            //cout << new_str <<endl;

            if (orig.compare(new_str) == 0)
                return true;
            else
                return false;
        }
};
int main()
{
    //string s("A man, a plan, a canal: Panama");
    string s("    ");

    Solution S;
    if (S.isPalindrome(s))
        cout <<"Is Palindrome" <<endl;

    return 0;
}
