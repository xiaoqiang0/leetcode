#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <limits>
#include <queue>
#include <map>
#include <cstring>
using namespace std;

class Solution {
    public:
        
        void gen(string &s, int idx, vector<string> &res, vector<string> &cur) {
            int left = 4 - cur.size();
            int len = s.length();
            if (idx == len && cur.size() == 4){
                string s;
                s = cur[0]+"."+cur[1]+"."+cur[2]+"."+cur[3];

                res.push_back(s);
                return;
            }
            for (int i = idx; i < len; i++){
                string t = s.substr(idx, i - idx + 1);
                int n = atoi(t.c_str());
                if (n < 0 || n > 255) break;
                if ((len - i - 1) > 3*(left-1)) continue;
                if ((len - i - 1) < (left-1)) break;
                if (s[idx] == '0' && i != idx) break;
                cur.push_back(s.substr(idx, i - idx + 1));
                gen(s, i+1, res, cur);
                cur.pop_back();
                if (s[idx] == '0') break;
            }
            

        }
        vector<string> restoreIpAddresses(string s) {
            vector<string> res;
            vector<string> cur;
            gen(s, 0, res, cur);

            return res;
        }
};
int main()
{
    //string s("1234573");
    //string s("25525511135");
    //string s("0000");
    string s("010010");
    Solution S;
    vector<string> res = S.restoreIpAddresses(s);

    for (int i = 0; i < res.size(); i ++)
        cout << res[i] <<endl;

    return 0;
}
