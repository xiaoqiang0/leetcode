#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector<int> res;
    vector<int> res1;
    res.push_back(1);
    res.push_back(2);
    int *a;
    a = new int(10);
    int n = 2;

    vector<vector<int> >rate (n, vector<int> (n));

    rate[0][0] = 1;
    rate[1][1] = 1;
//    res1 = res + 1;

    //std::find(res.begin(), res.end(), 1)!=res.end();
}
