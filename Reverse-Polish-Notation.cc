#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;


class Solution {
    public:
        int evalRPN(vector<string> &tokens) {
            stack<int> s;
            
            for (int i = 0;i < tokens.size(); i++){
                string str = tokens[i];

                if (str.length() == 1)
                    switch (str.at(0)) {
                        int op1, op2;
                        case '+':
                            op1 = s.top(); s.pop();
                            op2 = s.top(); s.pop();
                            s.push(op2 + op1 );
                            break;
                        case '-':
                            op1 = s.top(); s.pop();
                            op2 = s.top(); s.pop();
                            s.push(op2 - op1 );
                            break;
                        case '*':
                            op1 = s.top(); s.pop();
                            op2 = s.top(); s.pop();
                            s.push(op2 * op1 );
                            break;
                        case '/':
                            op1 = s.top(); s.pop();
                            op2 = s.top(); s.pop();
                            s.push(op2 / op1 );
                            break;
                        default:
                            s.push(atoi(str.c_str()));
                    }
                else 
                    s.push(atoi(str.c_str()));
            }
            return s.top();
        }
};

int main()
{
    vector<string> s;

/*    s.push_back("2");
    s.push_back("1");
    s.push_back("+");
    s.push_back("3");
    s.push_back("*");
*/
    s.push_back("-1");
    s.push_back("1");
    s.push_back("*");
    s.push_back("-1");
    s.push_back("+");

    Solution S;

    return S.evalRPN(s);
}
