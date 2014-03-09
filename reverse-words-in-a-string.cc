#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <limits>

using namespace std;
class Solution {
    public:
        void reverseWords(string &s) {
            vector<string> S;
            int start;
            int end = 0;
            while (1) {
                start = s.find_first_not_of(' ', end);
                if (start == string::npos)
                    break;
                end = s.find_first_of(' ', start);
                if (end == string::npos)
                    end = s.length();
                S.push_back(s.substr(start, end-start));
            }

            s.clear();
            
            if (S.size() == 0)
                return;

            s = S[S.size()-1];
            int n = S.size() - 2;

            while (n >= 0) {
                s = s + " " + S[n];
                n--;
            }
            
        }
};
int main()
{
    //string s("the sky is blue    ");
    string s("a");
    Solution S;
    S.reverseWords(s);

    cout << s<<endl;
    return 0;
}
