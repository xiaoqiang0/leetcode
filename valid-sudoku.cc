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
};
int main()
{
    vector<vector<char> > b(9, vector<char>(9, '.'));
    b[0][1] = '8';
    b[0][2] = '7';
    b[0][3] = '6';
    b[0][4] = '5';
    b[0][5] = '4';
    b[0][6] = '3';
    b[0][7] = '2';
    b[0][8] = '1';

    b[1][0] = '2';
    b[2][0] = '3';
    b[3][0] = '4';
    b[4][0] = '5';
    b[5][0] = '6';
    b[6][0] = '7';
    b[7][0] = '8';
    b[8][0] = '9';
    Solution S;
    if (S.isValidSudoku(b))
        cout <<"Valid SudoKu" << endl;


    return 0;
}
