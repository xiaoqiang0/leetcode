#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;


class Solution {
    public:
        struct Point{
            int i;
            int j;
            Point() :i(0), j(0) {}
            Point(int a, int b) : i(a), j(b) {}

        };
        int minimumTotal(vector<vector<int> > &triangle) {
            stack<Point> v;
            int n = triangle.size();
            int min = 100000; 
            int sum = 0;
            if (n == 0) return 0;
            if (n == 1) return triangle[0][0];

            v.push(Point(0,0));
            sum = triangle[0][0];
            while (1) {
                int i = v.top().i;
                int j = v.top().j;
                if (i == n - 1) {
                    if (sum < min)
                        min = sum;
                    if (j == n - 1)
                        break;
                    while (1) {
                        int t = v.top().j;
                        cout  << "POP  " << triangle[v.top().i][t]<<endl;
                        sum -=  triangle[v.top().i][t];
                        v.pop();
                        if (v.empty()) 
                            return min;
                        int k = v.top().j;
                        if (k == t) {
                            cout  << "PUSH- " <<triangle[v.top().i+1][v.top().j+1]<<endl;
                            sum += triangle[v.top().i+1][v.top().j+1];
                            if (sum > min){
                                sum -= triangle[v.top().i+1][v.top().j+1];
                                continue;
                            }
                            v.push(Point(v.top().i+1, v.top().j+1));
                            break;
                        }
                    }
                } else {
                    v.push(Point(i+1, j));
                    sum += triangle[i+1][j];
                    cout  << "PUSH " << triangle[i+1][j] <<endl;

                }
            }

            return min;
        }
};

int main()
{
    vector<vector<int> > v(3, vector<int>(3));
    v[0][0] = -1;
    v[1][0] = 2;v[1][1] = 3;
    v[2][0] = 1;v[2][1] = -1;v[2][2] = -3;

/*
    v[0][0] = 2;
    v[1][0] = 3;v[1][1] = 4;
    v[2][0] = 6;v[2][1] = 5;v[2][2] = 7;
    v[3][0] = 4;v[3][1] = 1;v[3][2] = 8;v[3][3] = 3;
*/
    Solution S;
    cout <<    S.minimumTotal(v) <<endl;
    return 0;
}
