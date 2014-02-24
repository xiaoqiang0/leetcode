#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
class Solution {
    public:
        string simplifyPath(string path) {
            vector<string> S;
            string res;

            int pre_pos = 0;
            int cur_pos = 0;
            pre_pos = path.find_first_not_of("/");
            while ((cur_pos = path.find("/", pre_pos)) != std::string::npos) {
                if (pre_pos == cur_pos){
                    pre_pos++;
                    continue;
                }
                string tmp = path.substr(pre_pos, cur_pos - pre_pos);
                pre_pos = cur_pos + 1;
                if (!tmp.compare("..")){
                    if (!S.empty())
                        S.pop_back();
                } else if (!tmp.compare("."))
                    continue;
                else {
                    S.push_back(tmp);
                    //cout <<"push: " << tmp<<endl;
                }
            }
            if (path[0] == '/')
                res = "/";
            if (path.size() - 1 >= pre_pos){
                string tmp= path.substr(pre_pos);
                if (!tmp.compare("..")){
                    if (!S.empty())
                        S.pop_back();
                } else if (!tmp.compare("."))
                    ;
                else
                    S.push_back(tmp);
            }
            if (S.size() > 0 )
                res = "";
            for (int i = 0; i < S.size(); i++) {
                res = res + "/" + S[i];
            }

            return res;
        }
};

int main()
{
    string path("/home/");
    string path1("/a/./b/../../c/");
    string path2("/VO/.././../..///F/Krh");
    string path3("/..");
    string path4("/.././GVzvE/./xBjU///../..///././//////T/../../.././zu/q/e");
    Solution S;
    cout << S.simplifyPath(path) <<endl;
    cout << S.simplifyPath(path1) <<endl;
    cout << S.simplifyPath(path2) <<endl;
    cout << S.simplifyPath(path3) <<endl;
    cout << S.simplifyPath(path4) <<endl;
    return 0;
}
