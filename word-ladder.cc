#include <set>
#include <unordered_set>
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <limits>
#include <queue>
#include <map>
#include <unordered_map>
using namespace std;
typedef pair<int, int> P; ///first是最短距离，second是顶点编号
class Solution {
    public:
        int ladderLength(string start, string end, unordered_set<string> &dict) {
            if (dict.find(start) != dict.end())
                dict.erase(start);
            if (dict.find(end) != dict.end())
                dict.erase(end);
            dict.insert(start);
            dict.insert(end);
            unordered_map<string, vector<string> > m;
            unordered_map<string, int > v;
            queue<string> Q;
            int N = dict.size();
            int len = start.length();
            int level = 1;
            bool found = false;
            Q.push(start);
            v[start] = 1;
            while (!Q.empty()){
                level++;
                int c = Q.size();
                for (int k = 0; k < c; k++){
                    string w = Q.front();
                    Q.pop();
                    for (int idx = 0; idx < len; idx++){
                        for (int s = 0; s < 26; s++){
                            string next = w;
                            int cc = 'a' + s;
                            next[idx] = cc;
                            if (dict.find(next) != dict.end() && v[next] == 0){
                                Q.push(next);
                                m[next].push_back(w);
                                v[next] = 1;
                                if (next.compare(end) == 0)
                                    return level;
                            }

                        }
                    }
                }
            }
            return 0;
        }       
};

int main()
{

    unordered_set<std::string> dict( {"hot","dot","dog","lot","log"});
    string s("hit");
    string e("cog");
    //unordered_set<std::string> dict( {"hot","dog"});
    //string s("hot");
    //string e("dog");
    Solution S;

    cout <<dict.size() <<endl;
    cout << S.ladderLength(s, e, dict) <<endl;;

    return 0;
}
