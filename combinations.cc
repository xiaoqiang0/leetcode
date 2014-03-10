#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <limits>

using namespace std;

class Solution {
    public:
        vector<vector<int> > combine(int n, int k) {
            vector<vector<int> >res;
            vector<int> cur;

            if (n == 0 || k == 0) return res;

            for (int i = 1; i <=k; i++)
                cur.push_back(i);
            
            res.push_back(cur);
            while (1){
                int t = -1;

                for (int i = k-1; i >= 0; i--)
                    if (cur[i] < n-k+1 + i) {
                        t = i;
                        break;
                    }
                if (t == -1) break;
                cur[t]++;

                for (int i = t+1; i<k; i++)
                    cur[i]=cur[i-1]+1;

                res.push_back(cur);
            }

            return res;
        }
};

int main()
{
    Solution S;
    vector<vector<int> > res = S.combine(6, 3);

    for (int i = 0; i < res.size(); i ++){
        for (int j = 0; j < res[i].size(); j++)
            cout << res[i][j];
        cout <<endl;
    }
    return 0;
}
