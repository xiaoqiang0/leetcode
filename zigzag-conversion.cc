#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;
class Solution {
    public:
        string convert(string s, int nRows) {
            int i;
            string res;

            if (s.empty()) return s;
            if (nRows == 1) return s;

            for (i = 0;i < nRows; i++){
                for (int j = i; j < s.length();){
                    res.push_back(s[j]);
                    if (i > 0 && i < nRows - 1){
                        int k = 2 * (nRows - i - 1) + j;
                        if (k >=s.length())
                            break;
                        res.push_back(s[2 * (nRows - i - 1) + j]);
                    }
                    j = j + 2*(nRows-1);
                }

            }
            return res;
        }
};

int main()
{
    Solution S;
    cout <<   S.convert("PAYPALISHIRING", 3) <<endl;
    return 0;
}
