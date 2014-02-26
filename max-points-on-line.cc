#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;
#define MAX     1000000
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

            if (n == 0|| n == 1 || n == 2) return n;

            vector<vector<int> > rate (n, vector<int> (n, 0));

            int sum = 2;
            int same = 1;
            for (i = 0; i < n - 1; i++){
                for (j = i+1; j < n; j++) {
                    if (points[i].x == points[j].x && points[i].y == points[j].y)
                        continue;
                    if (rate[i][j] == 1)
                        continue;
                    same = 0;
                    int t = 2;
                    rate[i][j] = rate[j][i] = 1;
                    for (k = 0; k < n; k++){
                        if (k == i || k == j)
                            continue;
                        if ((points[i].y - points[k].y) * (points[j].x - points[k].x) == \
                            (points[i].x - points[k].x) * (points[j].y - points[k].y) ) {
                            t++;
                            rate[i][k] = rate[j][k] = rate[k][i] = rate[k][j] = 1;
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
