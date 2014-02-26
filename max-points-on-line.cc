#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;
/**
 * Definition for a point.
 */
struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
    public:
        int maxPoints(vector<Point> &points) {
            int n = points.size();
            int i, j, k;
            #define MAX         10000000
            #define SAME        1000.0001
            if (n == 0|| n == 1 || n == 2) return n;

            vector<vector<int> > mark (n, vector<int> (n, 0));
            vector<vector<float> > rate(n, vector<float> (n, 0));


            for (i = 0; i < n - 1;i ++)
                for(j = i + 1 ; j < n; j++) {
                    if (points[i].x == points[j].x && points[i].y == points[j].y)
                        rate[i][j] = SAME;
                    else {
                        if (points[i].x = points[j].x)
                            rate[i][j] = MAX;
                        else 
                            rate[i][j] = (points[i].y - points[j].y) * 1.0 / (points[i].x - points[j].x);
                    }

                }

            int sum = 2;
            int same = 1;
            for (i = 0; i < n - 1; i++){
                for (j = i+1; j < n; j++) {
                    if (points[i].x == points[j].x && points[i].y == points[j].y)
                        continue;
                    if (mark[i][j] == 1)
                        continue;
                    same = 0;
                    int t = 2;
                    mark[i][j] = mark[j][i] = 1;
                    for (k = 0; k < n; k++){
                        if (k == i || k == j)
                            continue;
                        if (rate[i][j] == rate[i][k] || rate[i][k] == SAME || rate[j][k] == SAME){
                            t++;
                            mark[i][k] = mark[j][k] = mark[k][i] = mark[k][j] = 1;
                        }
                    }
                    if (t > sum)
                        sum = t;
                }
            }

            if (same == 1)
                return n;
            else
                return sum;
        }
};

int main()
{
    vector<Point> points;

    points.push_back(Point(1,2));
    points.push_back(Point(1,2));
    points.push_back(Point(7,8));
    points.push_back(Point(2,1));
    points.push_back(Point(1,2));
    points.push_back(Point(1,2));
    Solution S;

    cout <<"max points:" <<S.maxPoints(points) <<endl;

    return 0;

}
