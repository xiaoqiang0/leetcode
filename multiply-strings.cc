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
        string add(string &n1, string &n2){
            string res;
            int k = 0;
            if (n1.length() == 0)
                return n2;
            if (n2.length() == 0)
                return n1;
            int i = n1.length() - 1;
            int j = n2.length() - 1;

            while (i >= 0 || j >= 0){
                char l = '0',r = '0';

                if (i >= 0) l = n1[i--];
                if (j >= 0) r = n2[j--];
                char c = (k + l - '0' + r - '0') % 10 + '0';

                if ((k + l - '0' + r - '0') >= 10)
                    k = 1;
                else
                    k = 0;
                res.insert(0, 1, c);
            }
            if (k == 1) res.insert(0, 1, '1');
            return res;
        }
        string multiply(string num1, string num2) {
            string res("0");
            if (num1.compare("0") == 0 || num2.compare("0") == 0)
                return res;
            vector<string> v(10, string());
            v[0] = num1;
            for (int i = 1; i < 10; i++)
                v[i] = add(v[i-1], num1);
            int k = 0;
            for (int i = num2.length() -1 ; i >= 0; i--){
                string rh;

                if (num2[i] > '0')
                    rh = v[num2[i] - '0' -1];
                rh.insert(rh.length(), k, '0');
                res = add(res, rh);
                k++;
            }

            return res;
        }
};

int main()
{
    string n1("9");
    string n2("9");

    Solution S;
    cout <<S.multiply(n1, n2) <<endl;

    return 0;
}
