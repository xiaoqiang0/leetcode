#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <limits>
#include <set>

using namespace std;
class Solution {
    public:
        void gen(vector<int> &S, int i, vector<int> &cur, vector<vector<int> > &res){
            int n = S.size();
            if (i == n){
                res.push_back(cur);
            } else{
                gen(S, i+1, cur, res);
                cur.push_back(S[i]);gen(S, i+1, cur, res);
                cur.pop_back(); 
            }
        }

        vector<vector<int> > subsets(vector<int> &S) {
            vector<vector<int> > res;
            vector<int> cur;
            if (S.size() == 0)
                return res;
            sort(S.begin(), S.end());
            gen(S,0, cur, res);

            return res;
        }

        void gen2(vector<int> &S, int i, vector<int> &cur,set <vector<int> > &res){
            int n = S.size();
            if (i == n){
                res.insert(cur);
            } else{
                gen2(S, i+1, cur, res);
                cur.push_back(S[i]);gen2(S, i+1, cur, res);
                cur.pop_back(); 
            }
        }

        vector<vector<int> > subsetsWithDup(vector<int> &S) {
            vector<vector<int> > res;
            set <vector<int> > r;
            vector<int> cur;
            if (S.size() == 0)
                return res;
            sort(S.begin(), S.end());
            gen2(S,0, cur, r);
            res.assign(r.begin(), r.end());
            return res;
        }

};
int main()
{
    //int a[] = {4,1,0};
    int a[] = {1,2,2};
    vector<int> v;
    v.assign(a, a + sizeof(a)/sizeof(int));
    Solution S;
    vector<vector<int> >  res = S.subsetsWithDup(v);
    for (int i = 0; i < res.size(); i ++){
        for (int j = 0; j < res[i].size(); j++)
            cout <<res[i][j] << " ";
        cout <<endl;

    }
    return 0;
}
