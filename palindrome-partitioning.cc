#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <limits>
#include <map>

using namespace std;
class Solution {
    public:

        int is_palindrome(string &s, int i, int j)
        {
            for (int k = i; k <=(i+j)/2; k++)
                if (s[k] != s[j-k+i])
                    return 0;

            return 1;
        }
        void compute(string s, int i, map<int, vector<int> > &m, vector<string> &cur, vector<vector<string> > &res)
        {
            if (i == s.length()) {
                res.push_back(cur);
                return;
            }

            vector<int> &v = m[i];

            for (int j = 0; j < v.size(); j++){
                cur.push_back(s.substr(i, v[j]-i+1));
                compute(s, v[j]+1, m, cur, res);
                cur.pop_back();
            }

        }
        vector<vector<string> > partition(string s) {

            vector<vector<string> > res;
            vector<string> cur;
            map<int, vector<int> > m;

            for (int i = 0; i < s.length(); i++)
                for (int j = i; j < s.length(); j++)
                    if (is_palindrome(s, i, j) == 1){
                        m[i].push_back(j);
                     //   cout <<s.substr(i, j-i+1) <<endl;;
                    }

            compute(s, 0, m, cur, res);
             
            return res;
        }
};
int main()
{
    string str("aabcdcb");

    Solution S;
    vector<vector<string> > res = S.partition(str);

    for (int i = 0; i < res.size(); i ++){
        for(int j = 0; j < res[i].size(); j++)
            cout <<res[i][j]<< " ";
        cout <<endl;
    }
    return 0;
}
