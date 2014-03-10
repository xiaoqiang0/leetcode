#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <limits>
#include <set>

using namespace std;
class Solution {
    public:

        bool compute(vector<int> &candidates, int i, int target, vector<int> &cur, set<vector<int> > &res)
        {
            bool ret = false;
            int tmp = candidates[i];
            if (target == 0) {
                res.insert(cur);
                return true;
            }

            if (i == candidates.size())
                return false;
            if (candidates[i] > target) return false;
            for (int j = 0; j*tmp <= target; j ++){
                int k = j;
                while (k>0){
                    cur.push_back(tmp);
                    k--;
                }
                compute(candidates, i+1, target - j*tmp, cur, res);
                k = j;
                while (k>0){
                    cur.pop_back();
                    k--;
                }
            }
        }
        vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
            vector<vector<int> > res;
            vector<int> v;
            set<vector<int> > r;
            sort(candidates.begin(), candidates.end());
            compute(candidates, 0, target, v, r);
            res.assign(r.begin(), r.end());
            return res;
        }
};
int main()
{
    //int A[] = {2,3,6,7};
    int A[] = {8,7,4,3};
    //int A[] = {6,7};

    vector<int> v;
    v.assign(A, A+sizeof(A)/sizeof(int));


    Solution S;
    vector<vector<int> > res = S.combinationSum(v, 11);
    for (int i = 0; i <res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++){
            cout<< res[i][j] <<" ";
        }
        cout <<endl;
    }

}
