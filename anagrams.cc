#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <algorithm>
#include <string>
#include <limits>

#include <map>

using namespace std;

class Solution {
    public:
        vector<string> anagrams(vector<string> &strs) {
            map<string, vector<string> > m;
            vector<string> res;
            int n = strs.size();

            for (int i = 0; i < n; i++){
                string s = strs[i];
                string sorted = s;
                sort(sorted.begin(), sorted.end());
                if (m.find(sorted) == m.end())
                    m[sorted] = vector<string>(1, s);
                else
                    m[sorted].push_back(s);
            }
            
            for (std::map<string, vector<string> >::iterator it=m.begin(); it!=m.end(); ++it){
                string key = it->first;
                vector<string> values = it->second;
                if (values.size() == 1) continue;
                for(int i = 0; i < values.size(); i++)
                    res.push_back(values[i]);
            }
            return res;

        }
};
int main()
{
    vector<string> strs;
    strs.push_back("acb");
    strs.push_back("abc");
    strs.push_back("cba");
    strs.push_back("123");
    Solution S;
    vector<string> res = S.anagrams(strs);

    for (int i = 0; i < res.size(); i ++)
        cout <<res[i] <<endl;
    return 0;
}
