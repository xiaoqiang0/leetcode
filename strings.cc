#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>

using namespace std;

class my_cmp : public std::binary_function<string, string, bool>
{
    bool operator()(const string& s1,const string& s2) const
    { 
        return s1.compare(s2); 
    } 

};
class Solution {
    public:
        int max_prefix(string &s1, string &s2)
        {
            
            int l1 = s1.length();
            int l2 = s2.length();
            
            if (l1 == 0||l2 == 0)
                return 0;
            int i = 0;
            int min_len = ((l1 > l2)? l2 : l1);

            while (i <= min_len){
                if (s1[i] != s2[i])
                    break;
                i++;
            }

            return i;
        }

        string longestCommonPrefix(vector<string> &strs)
        {
            int n = strs.size();
            if (n == 0) return string();

            if (n == 1) return strs[0];

            std::sort(strs.begin(), strs.end());
            int max = max_prefix(strs[0], strs[1]);
            for (int i = 1; i < strs.size() - 1; i ++) {
                int cur_len = max_prefix(strs[i], strs[i+1]);
                if (max > cur_len)
                    max = cur_len;

            }
            return string(strs[0], 0, max);

        }
};

int main()
{
    vector<string> strs;
/*
    strs.push_back("11422");
    strs.push_back("11322");
    strs.push_back("11522");
    strs.push_back("22111");
    strs.push_back("11122");
*/
    Solution S;

    cout << S.longestCommonPrefix(strs) << endl;

    return 0;
}
