#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <limits>
#include <map>
using namespace std;
class Solution {
    public:
        void gen(string &digits, int k, map<char, string> &m, string &cur, vector<string> &res)
        {
            if (k == digits.size()) {
                res.push_back(cur);
                return;
            }

            if (digits[k] == '1' || digits[k] == '0')
                gen(digits, k+1, m, cur, res);
            else {
                string maps =  m[digits[k]];
                for (int i = 0; i < maps.size(); i++){
                    cur.push_back(maps[i]);
                    gen(digits, k+1, m, cur, res);
                    cur.erase(cur.length()-1, 1);
                }
            }
        }

        vector<string> letterCombinations(string digits) {

            vector<string> res;

            if (digits.length() == 0) {
                res.push_back("");
                return res;
            }

            map<char, string> m;
            string cur;

            m['1'] = "";
            m['2'] = "abc";
            m['3'] = "def";
            m['4'] = "ghi";
            m['5'] = "jkl";
            m['6'] = "mno";
            m['7'] = "pqrs";
            m['8'] = "tuv";
            m['9'] = "wxyz";

            gen(digits, 0, m, cur, res);

            return res;
        }
};
int main()
{
    Solution S;
    string str("10");
    vector<string> res = S.letterCombinations(str);

    for (int i = 0; i < res.size(); i++)
        cout <<res[i]<<endl;

    return 0;
}
