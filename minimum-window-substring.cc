#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <limits>
#include <queue>
#include <map>

using namespace std;
class Solution {
    public:
        string minWindow(string S, string T) {
            string res;
            map<char, int> m;
            

            int c = T.length();

            if (c == 0)
                return res;

            for (int i = 0; i < T.length(); i++){
                if (m[T[i]] >= 1)
                    m[T[i]] = m[T[i]]+1;
                else
                    m[T[i]] = 1;

             //   cout <<m[T[i]] <<endl;
            }

            int min = 100000;
            int cur = 0;
            int start = 0, end = -1;
            for (int i = 0; i < S.length(); i++){
                if (T.find(S[i]) == string::npos) {
                    if (c == T.length()){
                        start ++;
                        end ++;
                    } else {
                        end++;
                    }
                } else {
                    if (m[S[i]] <= 0) {
                        end++;
                        m[S[i]] = m[S[i]]-1;
                        //cout << S[i]<<"#"<<m[S[i]] <<endl;
                        continue;
                    }

                    m[S[i]] = m[S[i]]-1;
                    c--;
                    end++;
                    if(c == 0) {
                        int t;
                        do {
                            if (end - start + 1 < min){
                                min = end-start+1;
                                res = S.substr(start, end-start+1);
                            }
                            m[S[start]] = m[S[start]]+1;
                            t = start;
                            start = S.find_first_of(T, start+1);
                            //cout << start <<"->"<<end <<endl;
                            //cout << S[t]<<":"<<m[S[t]] <<endl;
                        } while (m[S[t]] <= 0);
                        c++;
                    }
                }
            }
            
            return res;
        }
};
int main()
{
    string s("ADOBECODEBANC");
    string t("ABC");
    Solution S;
    cout << S.minWindow(s, t) <<endl;;
    return 0;
}
