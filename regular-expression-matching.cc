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
        bool isMatch(const char *s, const char *p) {
            const char *r = s, *q = p;

            if (*s == '\0' && *p == '\0') return true;
            //p is not start with x*
            if (!(*p && *(p+1) && (*(p+1) == '*')))
                if (!(*s && *p ))
                    return false;
            if (*p == '.') {
                if (*(p+1) == '*')
                    return (*s && isMatch(s+1, p)) || isMatch(s, p+2);
                    //return isMatch(s, p+2) || isMatch(s+1, p);
                else
                    return (*s && isMatch(s+1, p+1));
            }

            if (*(p+1) == '*') 
                return isMatch(s, p+2) || (*s == *p && isMatch(s+1, p));
            else
                return (*s == *p && isMatch(s+1, p+1));
        }
};
int main()
{
    char *s = "aab";
    char *p = "c*a*b";

    Solution S;
    cout << S.isMatch(s, p) <<endl;
    return 0;
}
