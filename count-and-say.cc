#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
    public:
        string countAndSay(int n) {
            string res;
            string tmp;

            if (n == 0) return res;

            res = "1";
            while (n > 1) {
                int size = res.length();
                int idx = 0;
                tmp.erase(0);
                while (idx < size){
                    char c = res[idx];
                    int end = res.find_first_not_of(&c, idx);
                    if (end == string::npos){
                        end = size;
                    }
                    tmp.append(std::to_string(end - idx));
                    tmp.append(std::to_string(res[idx] - '0'));
                    idx = end;
                }
                res.assign(tmp);
                n--;
                cout <<res<<endl;
            }
            return string(res);
            
        }
};
int main()
{
    Solution S;
    //cout <<"11131221131211132221232112111312111213111213211231132132211211131221131211221321123113213221123113112221131112311332211211131221131211132211121312211231131112311211232221121321132132211331121321231231121113112221121321133112132112312321123113112221121113122113121113123112112322111213211322211312113211"<<endl<<endl;;
    cout << S.countAndSay(20) <<endl;
    return 0;
}
