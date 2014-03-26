#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <limits>

using namespace std;

class Solution {
    public:
        bool isValidSudoku(vector<vector<char> > &board) {

            //Rows Check
            for (int i = 0; i < 9; i++){
                int v[10] = {0}; 
                for (int j = 0; j < 9; j++){
                    if (board[i][j] == '.') continue;
                    if (v[board[i][j] - '0'] == 1)
                        return false;
                    v[board[i][j] - '0'] = 1;
                }
            }
            //Columns Check
            for (int i = 0; i < 9; i++){
                int v[10] = {0}; 
                for (int j = 0; j < 9; j++){
                    if (board[j][i] == '.') continue;
                    if (v[board[j][i] - '0'] == 1)
                        return false;
                    v[board[j][i] - '0'] = 1;
                }
            }
            
            //Box
            for (int i = 0; i < 9; i=i+3)
                for (int j = 0; j < 9; j=j+3) {
                    int v[10] = {0}; 
                    for (int s = i; s < i + 3; s++)
                        for (int t = j; t < j+3; t++) {
                            if (board[s][t] == '.') continue;
                            if (v[board[s][t] - '0'] == 1)
                                return false;
                            v[board[s][t] - '0'] = 1;
                        }
                }


            return true;
        }

        bool eval(vector<vector<char> > &b, int i, int j){
            int s, t;
            int v[10] = {0}; 
            //find first blank point
            int found = 0;
            if (i ==8 && j == 6)
                i = 0;
            for (s = i; s < 9; s++) {
                if (s == i)
                    t = j;
                else
                    t = 0;
                for (; t < 9; t++)
                    if (b[s][t] == '.'){
                        found = 1;
                        break;
                    }
            
                if (found == 1) break;
            }
            if (found == 0)
                return true;

            for (int c = 0; c < 9; c++){
                int T[10] = {0};
                if (b[s][c] != '.'){
                    if (T[b[s][c]-'0'] == 1)
                        return false;
                    v[b[s][c]-'0'] = 1;
                    T[b[s][c]-'0'] = 1;
                }
            }
            for (int c = 0; c < 9; c++){
                int T[10] = {0};
                if (b[c][t] != '.'){
                    if (T[b[c][t]-'0'] == 1)
                        return false;

                    v[b[c][t]-'0'] = 1;
                    T[b[c][t]-'0'] = 1;
                }
            }


            int p = s - (s%3);
            int q = t - (t%3);
            for (int m = p; m < p+3; m++){
                int T[10] = {0};
                for (int n = q;n < q+3; n++)
                    if (b[m][n] != '.'){
                        if (T[b[m][n]-'0'] == 1)
                            return false;
                        v[b[m][n]-'0'] = 1;
                        T[b[m][n]-'0'] = 1;
                    }
            }
            for (int c = 1; c <= 9; c++){
                bool ret = true;
                if (v[c] == 1) continue;
                if (b[s][t] != '.')
                    b[s][t] = b[s][t];
                b[s][t] = c + '0';
                if (s == 8 && t == 8) return true;
                if (t == 8)
                    ret = eval(b, s+1, 0);
                else
                    ret = eval(b, s, t+1);
                    
                if (ret == false)
                    b[s][t] = '.';
                else
                    return true;
                /*
                cout <<s << "##" << t<<endl;
                for (int ii = 0; ii < 9; ii++){
                    for (int jj = 0; jj < 9; jj++)
                        cout <<b[ii][jj];
                    cout <<" ";
                }
                cout <<endl;
                */
            }

            return false;
        }
        void solveSudoku(vector<vector<char> > &board) {
            eval(board, 0, 0);
        }
};
int main()
{
    vector<vector<char> > b(9, vector<char>(9, '.'));
    b[0][0] = '5';
    b[0][1] = '3';
    b[0][4] = '7';
    b[1][0] = '6';
    b[1][3] = '1';
    b[1][4] = '9';
    b[1][5] = '5';
    b[2][1] = '9';
    b[2][2] = '8';
    b[2][7] = '6';


    b[3][0] = '8';
    b[3][4] = '6';
    b[3][8] = '3';

    b[4][0] = '4';
    b[4][3] = '8';
    b[4][5] = '3';
    b[4][8] = '1';

    b[5][0] = '7';
    b[5][4] = '2';
    b[5][8] = '6';

    b[6][1] = '6';
    b[6][6] = '2';
    b[6][7] = '8';

    b[7][3] = '4';
    b[7][4] = '1';
    b[7][5] = '9';
    b[7][8] = '5';

    b[8][4] = '8';
    b[8][7] = '7';
    b[8][8] = '9';

    Solution S;
    if (S.isValidSudoku(b))
        cout <<"Valid SudoKu" << endl;

    S.solveSudoku(b);
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++)
            cout <<b[i][j];
        cout <<endl;
    }
    return 0;
}
