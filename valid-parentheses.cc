#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <limits>

using namespace std;
class Solution {
    public:
        bool isValid(string s) {
            stack<char> S;

            for (int i = 0; i < s.size(); i ++){
                char c = s[i];
                switch (c) {
                    case '(':
                    case '[':
                    case '{':
                        S.push(c);
                        break;
                    case '}':
                        if (S.empty() || S.top() != '{')
                            return false;
                        S.pop();
                        break;
                    case ']':
                        if (S.empty() || S.top() != '[')
                            return false;
                        S.pop();
                        break;
                    case ')':
                        if (S.empty() || S.top() != '(')
                            return false;
                        S.pop();
                        break;
                }
            }

            if (S.empty())
                return true;
            else 
                return false;
        }
};
int main()
{
    string s("()[]{}");
    Solution S;
    if (S.isValid(s))
        cout <<"Valid" <<endl;
    else 
        cout <<"Not Valid" <<endl;
    return 0;
}
