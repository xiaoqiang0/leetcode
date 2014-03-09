#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <limits>

using namespace std;

class Solution {
    public:
        int lengthOfLastWord(const char *s) {
            if (s == NULL) return 0;

            string str(s);

            if (str.length() == 0) return 0;
            

            int n = str.length();
            
            const char *p = s + n -1;

            while (p >= s && *p == ' ') p--;
            int k = 0;
            while (p >= s && *p != ' ') { p--; k++;}

            return k;

        }
};
int main()
{
    char *p = "hello world";
    Solution S;
    cout <<S.lengthOfLastWord(p) <<endl;

    return 0;
}
