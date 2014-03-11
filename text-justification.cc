#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <limits>
#include <string>
#include <queue>

using namespace std;

class Solution {
    public:
        vector<string> fullJustify(vector<string> &words, int L) {
            int pre = 0;
            int cur = 0;
            int d = L;
            vector<string> res;
            if (L == 0){
                res.push_back("");
                return res;
            }
            queue<string> Q;
            for (int i = 0; i < words.size(); i++){
                int len = words[i].length();
                int tagged = 0;
                if (len <= d) {
                    Q.push(words[i]);
                    tagged = 1;
                    d -= (len + 1);continue;
                }
                int size = Q.size();
                //(d+size)/(size-1);
                //addi = (d+size) % (size-1)
                //
                int ns;
                int addi; 
                if (size > 1) {
                    ns = (d+size)/(size-1);
                    addi = (d+size) % (size -1);
                } else{
                    ns = d+size;
                    addi = 0;
                }
                string s("");
                while(Q.size() > 1 && Q.empty() == false){
                    s += Q.front()+string(ns, ' ');
                    if (addi > 0)
                        s += string(1, ' ');
                    addi--;
                    Q.pop();
                }
                if (size > 1)
                    s += Q.front();
                else
                    s += Q.front()+string(ns, ' ');
                Q.pop();
                res.push_back(s);
                if (tagged == 0){
                    Q.push(words[i]);
                    d = L - len - 1;
                }
            }
            
            //Last Line
            string s("");
            while(Q.size() > 1 && Q.empty() == false){
                s += Q.front()+string(1, ' ');
                Q.pop();
            }
            if (Q.empty() == false) {
                d++;
                s += Q.front()+string(d, ' ');
                res.push_back(s);
            }
            
            return res;
        }
};
int main()
{
    vector<string> v;

    v.push_back("");
/*
    v.push_back("i");
    v.push_back("o");

    v.push_back("this");
    v.push_back("this");
    v.push_back("is");
    v.push_back("an");
    v.push_back("example");
    v.push_back("of");
    v.push_back("text");
    v.push_back("justificat");
    v.push_back("ju");
*/
    Solution S;
    vector<string> res = S.fullJustify(v, 2);

    for (int i = 0; i < res.size(); i ++)
        cout <<res[i]<<endl;
    return 0;
}
