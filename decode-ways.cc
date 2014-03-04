#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <limits>

using namespace std;
class Solution {
    public:
        int numDecodings(string s) {
            int n = s.length();

            vector<int> A(n, 0);

            if (n == 0) return 0;

            if (s[0] == '0')
                return 0;

            if (n == 1) return 1;

            A[0] = 1;
            int k = atoi(s.substr(0,2).c_str());

            if (k>=1 && k <=26 && (k != 10 && k != 20))
                A[1] = 2;
            else if (k >= 30 && k % 10 == 0)
                return 0;
            else {
                A[1] = 1;
                if (s[1] == '0')
                    A[0] = 0;
            }

            for (int i = 2; i < n; i++){
                int k = atoi(s.substr(i-1, 2).c_str());

                if (s[i] == '0')
                    A[i-1] = 0;

                if (s[i] == '0' && A[i-2] == 0)
                    return 0;

                if (k>=1 && k <=26)
                    A[i] = A[i-1]+A[i-2];
                else if (k == 0 )
                    return 0;
                else
                    A[i] = A[i-1];
            }

            return A[n-1];
        }
};

int main()
{
    //string s("123234123452");
    //string s("10");
    //string s("100");
    //string s("101"); //1
    string s("611");
    Solution S;
    cout <<S.numDecodings(s)<<endl;
    return 0;
}
