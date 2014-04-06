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
        bool isNumber(const char *s) {
            //integer
            //float
            // 2.5E12
            const char *p = s;
            //skip prefix spaces
            while (*p == ' ') p++;
           if (*p == '\0') return false;
            const char *q = p;
            int integer   = 0;
            double decimal  = 0;

            while(*q) q++;

            //skip trailing spaces
            while (q > p && *(q-1) == ' ') { q--;}


            //skip flag
            if (*p == '-' || *p == '+')  p++;
            // no more chars ? return fasle
            if (p == q) return false;

            while (*p >= '0' && *p <= '9') {
                integer = integer * 10 + *p - '0';
                p++;
            }

            if (*p == '.') { 
                const char *t = p;
                p++;
                double k = 0.1;
                double ko = 0.1;
                while (*p >= '0' && *p <= '9') {
                    decimal += k * (*p - '0');
                    k *= 0.1;
                    p++;
                }

                if (integer == 0 && decimal == 0 && k == ko &&   /*no sufix number */
                    !(s < t && *(t-1) >= '0' && *(t-1) <= '9'))  /*no prefix number */
                    return false;
            }

            // already additinal chars, but it's not E|e, return fasle;
            if (q > p && (*p != 'E' && *p != 'e'))
                return false;

            //*p == 'E|e'
            if (q > p && (*p == 'E' || *p == 'e')) {
                const char *t = p++;

                //skip +|-
                if (*p == '+' || *p == '-')
                    p++;

                //No more numbers behind E|e, return fasle;, like 123E, 124e;
                if (p == q) return false;

                // go though all numbers
                while (*p >= '0' && *p <= '9')
                    p++;
                // there're additianl non-numbers between p and q, return false;
                if (p < q) return false;
                double tt = integer + decimal;
                //There's additinal numbers before E|e, return true;
                if (tt>0 || (t>s && *(t-1) >= '0' && *(t-1) <= '9'))
                    return true;
                else
                    return false;
            }
            if (p == q)
                return true;
            else 
                return false;
        }
};
int main()
{
    Solution S;

    cout <<S.isNumber("e11")<<endl;
    cout <<S.isNumber("6e")<<endl;
    cout <<S.isNumber("6e1.1")<<endl;
    cout <<S.isNumber("0e1")<<endl;
    cout <<S.isNumber("+")<<endl;
    cout <<S.isNumber("4e+")<<endl;
    cout <<S.isNumber(" .")<<endl;
    cout <<S.isNumber("0.")<<endl;
    cout <<S.isNumber(".0")<<endl;
    cout <<S.isNumber("2e11")<<endl;
    cout <<S.isNumber("abc")<<endl;
    cout <<S.isNumber("1 ")<<endl;
    cout <<S.isNumber("0")<<endl;
    cout <<S.isNumber(" 0.1")<<endl;
    cout <<S.isNumber("1 a")<<endl;
    cout <<S.isNumber("12e11")<<endl;
    cout <<S.isNumber(".")<<endl;
    cout <<S.isNumber(" ")<<endl;
    return 0;
}
