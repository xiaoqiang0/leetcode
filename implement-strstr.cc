#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <limits>
#include <queue>
#include <map>
#include <cstring>

using namespace std;

class Solution {
    public:
        void get_next(char *T, int n, vector<int> &next){
            int i = 0;     
            next[i] = -1;    
            int j = -1;    
            while(i < n-1 ){    
                if( j == -1 || T[i] == T[j] ){   //循环的if部分 
                    ++i;    
                    ++j;    
                    //修正的地方就发生下面这4行    
                    if( T[i] != T[j] ) //++i，++j之后，再次判断T[i]与T[j]的关系    
                        next[i] = j;      //之前的错误解法就在于整个判断只有这一句。    
                    else    
                        next[i] = next[j];    
                } else                                 //循环的else部分    
                    j = next[j];    
            }  
        }

        char *strStr(char *haystack, char *needle) {

            if (haystack == NULL || needle == NULL)
            int slen = strlen(haystack);   
            int plen = strlen(needle);   
            vector<int> next(plen, 0);

            if (plen == 0) return haystack;

            get_next(needle, plen, next);

            int i = 0;    
            int j = 0;    
            int slen = strlen(haystack);
            while ( i < slen && j < plen )    {    
                if( j == -1 || haystack[i] == needle[j] ){    
                    ++i;    
                    ++j;    
                } else {    
                    j = next[j];              
                    //当匹配失败的时候直接用p[j_next]与s[i]比较，    
                    //下面阐述怎么求这个值，即匹配失效后下一次匹配的位置    
                }    
            }
            if( j >= plen )    
                return haystack + (i - plen);    
            else    
                return NULL;
            /*
            for (int i = 0; i < n; i ++)
                cout <<next[i];
            cout <<endl;
            */

        }
};
int main ()
{

    char s[] = "acabaabaabcacaabc";
    char t[] = "abaabcac";
    Solution S;
    cout << S.strStr(s, t) <<endl;
    cout << t <<endl;
    return 0;
}
