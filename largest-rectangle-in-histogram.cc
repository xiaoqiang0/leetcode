#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <limits>

using namespace std;
class Solution {
    public:
        /*分治思想*/
        int eval(vector<int> &height, int l, int u){
            if (l == u) return height[l];

            int mid = (l+u)/2;

            int l_max = eval(height, l, mid);
            int r_max = eval(height, mid+1, u);

            int s = mid,t = mid+1;
            int low = min(height[s], height[t]);

            int mid_max = low*2;
            if (mid_max == 0)
                return max(l_max, r_max);

            while(s > l || t < u){
                int ln = -1;
                int rn = -1;
                if (s > l)
                    ln = height[s-1];
                if (t < u)
                    rn = height[t+1];

                //find the latter and move to it;
                if (ln < rn) {
                    t++;
                    low = min(rn, low);
                } else if (ln > rn) {
                    s--;
                    low = min(ln, low);
                } else {
                    t++;
                    s--;
                    low = min(ln, low);
                }
                mid_max = max(low * (t-s+1), mid_max);
            }

            return max(max(l_max, r_max), mid_max);
        }
        int largestRectangleArea(vector<int> &height) {
            if (height.size() == 0) return 0;
            return eval(height, 0, height.size()-1);
        }
};

int main()
{
    int A[] = {2,1,5,6,2,3};
    //int A[] = {2};
    
    vector<int > v;

    v.assign(A, A+sizeof(A)/sizeof(int));

    Solution S;
    cout << "MAX:" <<S.largestRectangleArea(v) <<endl;
    return 0;
}
