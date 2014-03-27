#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <limits>
#include <queue>
#include <map>

using namespace std;
/*
   两次分治:
    1. 按行分治
    2. 按列分治

   复杂度分析:
    f(n) = 2 * f(n/2) + t(n);

    t(n) = 2 * t(n/2) + n^2;

    t(n) ~ O(n^2);

    So, f(n) ~ O(n^2);
 */
class Solution {
    public:
        /*Get the range of sub matrix(n * 1), with the middle position(i,j)*/
        void get_lu(vector<vector<char> > &m, int t, int b, int i, int j, int &l, int &u){
            for (int k = i; k >= t; k--){
                if (m[k][j] == '0') break;
                l = k;
            }
            for (int k = i; k <= b; k++){
                if (m[k][j] == '0') break;
                u = k;
            }
        }
        /* get the maximal rectangle cross (t,l) <=> (b,u)*/
        int eval_mid(vector<vector<char> > &m, int t, int b, int l, int u){
            if (l == u){
                int res = 0;
                int mid = (t+b)/2;
                for (int i = mid; i >=t; i--){
                    if (m[i][l] == '0')
                        break;
                    res++;
                }

                for (int i = mid+1; i <=b; i++){
                    if (m[i][l] == '0')
                        break;
                    res++;
                }

                return res;
            }
            
            int mid = (l+u)/2;
            int l_max = eval_mid(m, t, b, l, mid);
            int r_max = eval_mid(m, t, b, mid+1, u);
            int mid_max = 0;
            int rl = 0, ru = 10000;
            for (int i = mid; i >= l; i--){
                int tl, tu;
                if (l == 3 && u == 4 && t == 0 && b == 9)
                    tl = 1;
                get_lu(m, t, b, (t+b)/2, i, tl, tu);
                rl = max(rl, tl);
                ru = min(ru, tu);

                int cl = rl, cu = ru;
                for (int j = mid+1; j <= u; j++){
                    get_lu(m, t, b, (t+b)/2, j, tl, tu);
                    cl = max(cl, tl);
                    cu = min(cu, tu);
                    mid_max = max(mid_max, (j-i+1) * (cu-cl+1));
                }
            
            }
            
            return max(max(l_max, r_max), mid_max);
        }

        /*get the maximal rectangle for row 't' to 'b'*/
        int eval(vector<vector<char> > &m, int t, int b){
            if (t == b){
                int idx = 0; //matrix[t];
                int res = 0;
                int cur = 0;
                for (int i = 0; i < m[t].size(); i++){
                    if (m[t][i] == '0') {
                        res = max(cur, res);
                        cur = 0;
                    } else
                        cur ++;
                }
                return max(cur, res);
            }

            int mid = (t+b)/2;
            int t_max = eval(m, t, mid);
            int b_max = eval(m, mid+1, b);
            
            int l = -1, u = -1;
            int mid_max = 0;
            for (int i = 0; i < m[mid].size(); i ++){
                if (m[mid][i] == '1' && m[mid+1][i] == '1'){
                    if (l == -1)
                        l = i;
                    u = i;
                } else if (l != -1){
                    mid_max = max(eval_mid(m, t, b, l, u), mid_max);
                    l = -1;
                    u = -1;
                }
            }
            
            if (l != -1){
                mid_max = max(eval_mid(m, t, b, l, u), mid_max);
            }
            return max(max(t_max, b_max), mid_max);
        }

        int maximalRectangle(vector<vector<char> > &matrix) {
            if (matrix.size() == 0) return 0;
            return eval(matrix,0, matrix.size()-1);
        }
};
int main()
{
    /*
    string s[10] = {"101001110","111000001","001100011","011001001","110110010","011111101","101110010","111010001","011110010","100111000"};
    vector<vector<char> > v(10, vector<char>(9, '0'));
    for (int i = 0; i < 10; i++)
        v[i].assign(s[i].begin(), s[i].end());
*/
    string s[2] = {"11", "11"};
    vector<vector<char> > v(2, vector<char>(2, '0'));
    for (int i = 0; i < 2; i++)
        v[i].assign(s[i].begin(), s[i].end());
    Solution S;
    cout << S.maximalRectangle(v) <<endl;;
    return 0;
}
