#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;
class Solution {
    public:
        vector<int> grayCode(int n) {
            vector<int> res(1, 0);
            vector<int> res1;
            if (n == 0) return res;

            int flag = 0;
            while (n > 0)  {
                int size = res.size();
                flag = 0;
                while (size) {
                    int t = res[res.size() - 1];
                    if (flag == 0){
                        res.insert(res.begin(), t * 2);
                        res.insert(res.begin(), t * 2 + 1);
                    } else {
                        res.insert(res.begin(), t * 2 + 1);
                        res.insert(res.begin(), t * 2);
                    }
                    res.pop_back();
                    size --;
                    flag = (flag + 1) % 2;
                }

                n -- ;   
            }
            for (int i = 0; i < res.size(); i ++)
                res1.insert(res1.begin(), res[i]);
            return res1;
        }
};


int main()
{   Solution S;
    vector<int> res = S.grayCode(2);

    for (int i = 0; i < res.size(); i ++)
        cout << res[i] << " ";

    cout <<endl;
    return 0;
}
