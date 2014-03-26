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
        bool exist(vector<vector<char> > &board, string word) {
            int M = board.size();
            if (M == 0) return false;
            int N = board[0].size();
            

            for (int i = 0; i < board.size(); i ++)
                for (int j = 0; j < board[i].size(); j++){
                    if (board[i][j] != word[0]) continue;
                    vector<vector<int> > v(M, vector<int>(N, 0));

                    //cout << i << "," << j<<endl;
                    stack<pair<int, pair<int, int> > > S;
                    S.push(make_pair(0, make_pair(i, j)));
                    v[i][j] = 1;
                    bool flag = true;
                    if (S.size() == word.length())
                        return true;
                    while (!S.empty() && flag == true && S.size() < word.length()){
                        char c = word[S.size()];
                        pair<int, pair<int, int> > x = S.top();
                        int s = x.second.first;
                        int t = x.second.second;
                        //cout <<x.first << "#"<< "(" <<s << ","<< t<<")"<< board[s][t] << S.size() <<endl;
                        S.pop();
                        switch(x.first){
                            case 0:
                                x.first++;
                                if (t == N-1||c != board[s][t+1] || v[s][t+1] == 1){
                                    S.push(x);
                                } else {
                                    S.push(x);
                                    S.push(make_pair(0, make_pair(s, t+1)));
                                    v[s][t+1] = 1;
                                }
                                break;
                            case 1:
                                x.first++;
                                if (s == M-1||c != board[s+1][t] || v[s+1][t] == 1){
                                    S.push(x);
                                } else{
                                    S.push(x);
                                    S.push(make_pair(0, make_pair(s+1, t)));
                                    v[s+1][t] = 1;
                                }
                                break;
                            case 2:
                                x.first++;
                                if (t == 0||c != board[s][t-1] || v[s][t-1] == 1){
                                    S.push(x);
                                } else {
                                    S.push(x);
                                    S.push(make_pair(0, make_pair(s, t-1)));
                                    v[s][t-1] = 1;
                                }
                                break;
                            case 3:
                                x.first++;
                                if (s == 0||c != board[s-1][t]||v[s-1][t] == 1){
                                    if (S.size() == 0)
                                        flag = false;
                                    v[s][t] = 0;
                                }else {
                                    S.push(x);
                                    S.push(make_pair(0, make_pair(s-1, t)));
                                    v[s-1][t] = 1;
                                }
                                break;
                            case 4:
                                S.pop();
                                v[s][t] = 0;
                        }

                        if (S.size() == word.length())
                            return true;
                    }

                }

            return false;
        }
};
int main()
{
    /*
       ["ABCE"]
       ["SFCS"]
       ["ADEE"]
     */
    /*
    string A[3] = {"ABCE", "SFCS", "ADEE"};
    vector<vector<char> > b(3, vector<char>(4, '.'));
    b[0].assign(A[0].begin(), A[0].end());
    b[1].assign(A[1].begin(), A[1].end());
    b[2].assign(A[2].begin(), A[2].end());
    */
//    string A[57] = {"gbgptkbnfcxdxdohfcwhyopseabpqsawuinpvqectbfsgtznyxuwolrslukemkagvqxsgcuzfarovsbtqysgjlyvf",
    string A[3] = {"ABCE",
                   "SFES",
                   "ADEE"};

    vector<vector<char> > b(3, vector<char>(4, '.'));

    for (int i = 0; i < 3; i++)
        b[i].assign(A[i].begin(), A[i].end());

    Solution S;

    if (S.exist(b, "ABCEFSADEESE"))
        cout << "exist" <<endl;
    else
        cout << "not exist" <<endl;
    
    return 0;

    if (S.exist(b, "SEE"))
        cout << "exist" <<endl;
    else
        cout << "not exist" <<endl;

    if (S.exist(b, "ABCB"))
        cout << "exist" <<endl;
    else
        cout << "not exist" <<endl;

    return 0;
}
