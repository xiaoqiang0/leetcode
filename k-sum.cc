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
        vector<int> twoSum(vector<int> &numbers, int target) {
            vector<int> v;

            v.assign(numbers.begin(), numbers.end());
            sort(v.begin(), v.end());
            vector<int> res;
            int i = 0, j = v.size() - 1;
            while (i < j) {
                if (v[i] + v[j] < target)
                    i++;
                else if (v[i] + v[j] > target)
                    j--;
                else {
                    int l = -1, r = -1;
                    for (int k = 0; k < v.size(); k++){
                        if (numbers[k] == v[i] &&  l == -1) {
                            l = k; 
                        } else if (numbers[k] == v[j] && r == -1)
                            r = k;
                    }
                    if (l < r){
                        res.push_back(l+1);
                        res.push_back(r+1);
                    } else {
                        res.push_back(r+1);
                        res.push_back(l+1);
                    }
                    return res;
                }
            }
        }
};

int main()
{
    int A[] = {0,4,0};
    vector<int> v;
    v.assign(A, A+sizeof(A)/sizeof(int));

    Solution S;
    vector<int > r = S.twoSum(v, 0);

    cout <<"result:" << r[0] << "," << r[1] <<endl;
    return 0;
}
