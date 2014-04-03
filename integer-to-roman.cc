#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <limits>
#include <queue>
#include <map>
#include <unordered_map>
using namespace std;
class Solution {
    public:
        int romanToInt(string s) {
            unordered_map<char, int> charToInt = {
                                { 'I', 1 },
                                { 'V', 5 },
                                { 'X', 10 },
                                { 'L', 50 },
                                { 'C', 100 },
                                { 'D', 500 },
                                { 'M', 1000 }
                        };
            int result = 0;
            int index = s.length() - 1;
            int preInt = 0;
            while (index >= 0) {
                char ch = s[index];
                int curInt = charToInt[ch];
                if (curInt >= preInt)
                    result += curInt;
                else
                    result -= curInt;

                preInt = curInt;
                index--;
            }

            return result;
        }
        string intToRoman(int num) {
            string res;
            while (num) {
                if (num >= 1000) {
                    res += "M";
                    num -= 1000;
                } else if (num >= 900){
                    res += "CM";
                    num -= 900;
                } else if (num >= 500) {
                    res += "D";
                    num -= 500;
                } else if (num >= 400) {
                    res += "CD";
                    num -= 400;
                } else if (num >= 100) {
                    res += "C";
                    num -= 100;
                } else if (num >= 90){
                    res += "XC";
                    num -= 90;
                } else if (num >= 50) {
                    res += "L";
                    num -= 50;
                } else if (num >= 40) {
                    res += "XL";
                    num -= 40;
                } else if (num >= 10) {
                    res += "X";
                    num -= 10;
                } else if (num == 9) {
                    res += "IX";
                    num = 0;
                } else if (num >= 5) {
                    res += "V";
                    num -= 5;
                } else if (num == 4){
                    res += "IV";
                    num = 0;
                } else {
                    while (num){
                        res += "I";
                        num--;
                    }
                }

            }

            return res;
        }
};
int main()
{
    Solution S;
    cout << S.intToRoman(3856) <<endl;
    return 0;
}
