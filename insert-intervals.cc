#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <limits>
#include <queue>
#include <map>

using namespace std;
/**
 * Definition for an interval.
 */
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
bool cmpInter (Interval a, Interval b) { return (a.start < b.start); }

class Solution {
    public:
        vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
            vector<Interval> res;
            
            if (intervals.size() == 0){
                res.push_back(newInterval);
                return res;
            }

            int l = 0, u = intervals.size() - 1;

            while (l < u) {
                int k = (l+u)/2;
                if (intervals[k].start >= newInterval.start)
                    u = k-1;
                else
                    l = k+1;
            }
            u = (u < 0 ? 0: u);
            while (u < intervals.size() && intervals[u].start < newInterval.start){
                u++; 
            }
            intervals.insert(intervals.begin() + u, newInterval);

            int reset = 1, s, e;
            
            for (int i = 0; i < intervals.size(); i ++) {
                if (reset == 1) {
                    s = intervals[i].start;
                    e = intervals[i].end;
                    reset = 0;
                    continue;
                }
                if (e >= intervals[i].start) {
                    e = (e > intervals[i].end) ? e : intervals[i].end;
                } else {
                    res.push_back(Interval(s, e));
                    reset = 1;
                    i--;
                }
            }

            res.push_back(Interval(s, e));



            return res;
        }
};
int main()
{
    vector<Interval> v;

    v.push_back(Interval(1,5));
    v.push_back(Interval(6,8));
    Interval newInter(0, 9);
/*
    v.push_back(Interval(1,2));
    v.push_back(Interval(3,5));
    v.push_back(Interval(6,7));
    v.push_back(Interval(8,10));
    v.push_back(Interval(12,16));
    Interval newInter(4, 9);

    v.push_back(Interval(1,3));
    v.push_back(Interval(6,9));
    Interval newInter(2, 5);
*/
    Solution S;
    vector<Interval> intervals = S.insert(v, newInter);
    for (int i = 0; i < intervals.size(); i++)
        cout << intervals[i].start << "," << intervals[i].end << endl;

    return 0;
}
