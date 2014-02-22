#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;
class Solution {
    public:
        int numTrees(int n) {
            int sum;
            if (n == 1) return 1;
            if (n == 2) return 2;

            sum = 2 * numTrees(n - 1);

            for (int i = 1; i <= n-2; i++) {
                sum += numTrees(i) * numTrees(n - 1 - i);
            }

            return sum;
        }
};

int main()
{
    Solution S;
    cout << "numTrees(3):" <<S.numTrees(3)<<endl;
    cout << "numTrees(4):" <<S.numTrees(4)<<endl;
    cout << "numTrees(5):" <<S.numTrees(5)<<endl;
    return 0;
}
