#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#include <map>
#include <unordered_set>
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
    
    string s;
    s.append(to_string (12));
    cout <<s;
    //--------------------------------
    unordered_set<std::string> A( {"log", "dog", "hot", "hit"});
    unordered_set<std::string> B( {"hit", "hot"});
    unordered_set<std::string> C;

    set_intersection(A.begin(), A.end(), B.begin(), B.end(), std::insert_iterator< std::unordered_set<string> >(C,C.begin()));

    for (auto it = C.begin(); it != C.end(); it++)
        cout <<*it <<endl;

    //std::find(res.begin(), res.end(), 1)!=res.end();
}
