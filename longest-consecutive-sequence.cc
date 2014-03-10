#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <limits>
#include <bitset>

using namespace std;
class Solution {
    public:
        int longestConsecutive(vector<int> &num) {
            if (num.size() == 0) return 0;
            int max = num[0];
            int min = num[0];
            for (int i = 1; i < num.size(); i ++)
                if (min > num[i])
                    min = num[i];


            if (min < 0)
                for (int i = 0; i < num.size(); i ++)
                    num[i]-= min;
            max=num[0];

            for (int i = 1; i < num.size(); i ++)
                if (max < num[i])
                    max = num[i];

            vector<bool> b(max+1, false);

            for (int i = 0; i < num.size(); i++)
                b[num[i]] = true;

            int maxlen = 0;
            int curlen = 0;

            for (int i = 0; i <=max; i++){
                if (b[i] == true)
                   curlen++;
                else {
                    if (maxlen < curlen) maxlen = curlen;
                    curlen = 0;
                }
            }

            if (curlen > maxlen) maxlen = curlen;

            return maxlen;

        }
};
int main()
{
    //int A[] = {100, 4, 200, 1, 3, 2};
    int A[] = {0, -1};

    vector<int> v;
    v.assign(A, A+sizeof(A)/sizeof(int));

    Solution S;

    cout << "longestConsecutive:" << S.longestConsecutive(v)<<endl;

    return 0;
}
