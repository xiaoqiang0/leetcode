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
        bool wordBreak(string s, unordered_set<string> &dict) {
            vector<int> d(s.length()+1, 0);

            d[0] = 1;

            for (int i = 1; i <= s.length(); i++){
                for (int j = 0; j < i; j++){
                    if (d[j] == 0) continue;

                    string sub(s.substr(j, i-j));

                    if (dict.find(sub) != dict.end()){
                        d[i] = 1;
                        break;
                    }
                }
            }
            /*
            cout <<s<<endl;
            for (int i = 0; i < s.length()+1; i++)
                cout <<d[i];
            cout <<endl;
            */

            return d[s.length()] == 1;
        }
};
int main()
{
    unordered_set<std::string> dict( {"red","green","blue"} );
    string s("redblue");
    Solution S;
    S.wordBreak(s, dict);
    return 0;
}
