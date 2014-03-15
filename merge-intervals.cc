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
        vector<Interval> merge(vector<Interval> &intervals) {
            vector<Interval> res;
            
            sort(intervals.begin(), intervals.end(), cmpInter);
            
            if (intervals.size() <= 1)
                return intervals;

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
    v.push_back(Interval(1,3));
    v.push_back(Interval(8,10));
    v.push_back(Interval(15,18));
    v.push_back(Interval(2,6));
    Solution S;
    vector<Interval> intervals = S.merge(v);
    for (int i = 0; i < intervals.size(); i++)
        cout << intervals[i].start <<endl;


    return 0;
}
