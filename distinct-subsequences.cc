#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <limits>


using namespace std;
class Solution {
    public:
        int compute(string S, int i, string T, int j, vector<vector<int> > &v) {
            int sum = 0;

            if (i > S.length())
                return 0;

            if (j == T.length()) {
                v[i][j] += 1;
                return v[i][j];
            }

            if (v[i][j] != 0) return v[i][j];

            if (S[i] == T[j]){
                sum += compute(S, i+1, T, j+1, v);
                sum += compute(S, i+1, T, j, v);
            } else {
                sum += compute(S, i+1, T, j, v);
            }

            v[i][j] = sum;

            return sum;
        }
        int numDistinct1(string S, string T) {
            int n = 0;
            vector<vector<int> > v(S.length() +1 , vector<int>(T.length()+1, 0));
            n = compute(S, 0, T, 0, v);
            return n;
        }

        int numDistinct(string S, string T) {
            int n = 0;
            vector<vector<int> > v(S.length() +1 , vector<int>(T.length()+1, 0));
            
            if (S.length() == 0||T.length() == 0)
                return 0;

            if (S[0] == T[0])
                v[0][0] = 1;

            for (int j = 1; j < S.length(); j++)
                if (T[0] == S[j])
                    v[j][0] = v[j-1][0] + 1;
                else
                    v[j][0] = v[j-1][0];
            for (int i = 1; i < T.length(); i++)
                    v[0][i] = 0; 

            for (int i = 1; i < T.length(); i++)
                for (int j = i; j < S.length(); j ++) {
                    if (T[i] == S[j])
                        v[j][i] = v[j-1][i-1] + v[j-1][i];
                    else
                        v[j][i] = v[j-1][i];
                }

            return v[S.length()-1][T.length()-1];
        }
};
int main()
{
    //string S("b");
    //string T("a");
    //    string S("bbi");
    //    string T("bi");

    string S("aabdbaabeeadcbbdedacbbeecbabebaeeecaeabaedadcbdbcdaabebdadbbaeabdadeaabbabbecebbebcaddaacccebeaeedababedeacdeaaaeeaecbe");
    string T("bddabdcae");


    //string S("xslledayhxhadmctrliaxqpokyezcfhzaskeykchkmhpyjipxtsuljkwkovmvelvwxzwieeuqnjozrfwmzsylcwvsthnxujvrkszqwtglewkycikdaiocglwzukwovsghkhyidevhbgffoqkpabthmqihcfxxzdejletqjoxmwftlxfcxgxgvpperwbqvhxgsbbkmphyomtbjzdjhcrcsggleiczpbfjcgtpycpmrjnckslrwduqlccqmgrdhxolfjafmsrfdghnatexyanldrdpxvvgujsztuffoymrfteholgonuaqndinadtumnuhkboyzaqguwqijwxxszngextfcozpetyownmyneehdwqmtpjloztswmzzdzqhuoxrblppqvyvsqhnhryvqsqogpnlqfulurexdtovqpqkfxxnqykgscxaskmksivoazlducanrqxynxlgvwonalpsyddqmaemcrrwvrjmjjnygyebwtqxehrclwsxzylbqexnxjcgspeynlbmetlkacnnbhmaizbadynajpibepbuacggxrqavfnwpcwxbzxfymhjcslghmajrirqzjqxpgtgisfjreqrqabssobbadmtmdknmakdigjqyqcruujlwmfoagrckdwyiglviyyrekjealvvigiesnvuumxgsveadrxlpwetioxibtdjblowblqvzpbrmhupyrdophjxvhgzclidzybajuxllacyhyphssvhcffxonysahvzhzbttyeeyiefhunbokiqrpqfcoxdxvefugapeevdoakxwzykmhbdytjbhigffkmbqmqxsoaiomgmmgwapzdosorcxxhejvgajyzdmzlcntqbapbpofdjtulstuzdrffafedufqwsknumcxbschdybosxkrabyfdejgyozwillcxpcaiehlelczioskqtptzaczobvyojdlyflilvwqgyrqmjaeepydrcchfyftjighntqzoo");
    //string T("rwmimatmhydhbujebqehjprrwfkoebcxxqfktayaaeheys");
    Solution SS;
    cout << S.length()<<endl;
    cout <<SS.numDistinct(S, T) <<endl; 

    return 0;
}

