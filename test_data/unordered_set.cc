#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;
int main ()
{
    std::unordered_set<std::string> myset = { "red","green","blue" };

    std::string input;
    
    myset.insert("red");
    for (auto it = myset.begin(); it != myset.end();it++)
        cout <<*it<<endl;

    std::cout << std::endl;

    return 0;
}
