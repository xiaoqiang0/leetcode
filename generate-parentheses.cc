#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <algorithm>
#include <string>
#include <limits>

#include <queue>
using namespace std;
class Solution {
    public:
        vector<string> generateParenthesis(int n) {
            vector<string> res;
            set<string> all;
            string s("()");
            if (n == 0) return res;
            if (n == 1) {
                res.push_back(s);
                return res;
            }
            all.insert(s);
            n--;
            while(n){
                res.clear();
                res.assign(all.begin(), all.end());
                all.clear();
                for (int i = 0; i < res.size(); i++){
                    s = res[i];
                    int k = s.length();
                    while (k){
                        string t = s;
                        t.insert(k, "()");
                        all.insert(t);
                        k--;
                    }
                
                }
                n--;
            }
            res.clear();
            res.assign(all.begin(), all.end());
            return res;
        }
};
int main()
{
    Solution S;
    vector<string> r;
    r = S.generateParenthesis(4);
    for (int i = 0; i < r.size(); i ++)
        cout <<r[i] <<endl;
    return 0;
}
