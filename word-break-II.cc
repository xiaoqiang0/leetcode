#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <limits>
#include <queue>
#include <map>
#include <unordered_set>

using namespace std;
class Solution {
    public:
        void generate(string &s, int idx, vector<vector<int> >&v, vector<string> &cur, vector<string> &res){
             if (idx == 0){
                string t;
                t.clear();
                for (int i = cur.size() - 1; i > 0; i --)
                    t += cur[i] + " ";

                t += cur[0];
                res.push_back(t);

                return;
             }
             vector<int> &d = v[idx];


             for (int i = 0; i < d.size(); i++){
                cur.push_back(s.substr(d[i], idx - d[i]));
                generate(s, d[i], v, cur, res);
                cur.pop_back();
             }

             return;
        }
        vector<string> wordBreak(string s, unordered_set<string> &dict) {
            vector<string> res;
            vector<string> cur;
            vector<vector<int> >v(s.length()+1, vector<int>());
            v[0].push_back(-1);
            for (int i = 1; i <= s.length(); i++){
                for (int j = 0; j < i; j++){
                    if (v[j].size() == 0) continue;

                    string sub(s.substr(j, i-j));

                    if (dict.find(sub) != dict.end()){
                        v[i].push_back(j);
                    }
                }
            }

            generate(s, s.length(), v, cur, res);

            return res;
        }
};
int main()
{
    unordered_set<std::string> dict( {"cat", "cats", "and", "sand", "dog"} );
    string s("catsanddog");
    Solution S;
    vector<string> res = S.wordBreak(s, dict);
    for (int i = 0; i< res.size(); i ++)
        cout << res[i]<<endl;

    return 0;
}
