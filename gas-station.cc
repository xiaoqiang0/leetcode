#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <limits>

using namespace std;
class Solution {
    public:
        int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
            int max = -10000;
            int idx = -1;
            int cur = 0;
            for (int i = gas.size() - 1; i >=0; i--){
                cur += gas[i]-cost[i];
                if (cur > max) {
                    idx = i;
                    max = cur;
                }
            }

            if(cur < 0) return -1;

            return idx;
        }
};
int main()
{
    int A[] = {4};
    int B[] = {2};

    vector<int> gas;
    vector<int> cost;

    gas.assign(A, A+sizeof(A)/sizeof(int));
    cost.assign(B, B+sizeof(B)/sizeof(int));

    Solution S;
    cout <<S.canCompleteCircuit(gas, cost) <<endl;;
    return 0;
}
