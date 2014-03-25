#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <limits>
#include <queue>
#include <map>
#include <set>

using namespace std;
class Solution {
    public:
        vector<int> twoSum(vector<int> &numbers, int target) {
            vector<int> v;

            v.assign(numbers.begin(), numbers.end());
            sort(v.begin(), v.end());
            vector<int> res;
            int i = 0, j = v.size() - 1;
            while (i < j) {
                if (v[i] + v[j] < target)
                    i++;
                else if (v[i] + v[j] > target)
                    j--;
                else {
                    int l = -1, r = -1;
                    for (int k = 0; k < v.size(); k++){
                        if (numbers[k] == v[i] &&  l == -1) {
                            l = k; 
                        } else if (numbers[k] == v[j] && r == -1)
                            r = k;
                    }
                    if (l < r){
                        res.push_back(l+1);
                        res.push_back(r+1);
                    } else {
                        res.push_back(r+1);
                        res.push_back(l+1);
                    }
                    return res;
                }
            }
        }

        vector<vector<int> > threeSum1(vector<int> &num) {
            vector<vector<int> >res;
            set<vector<int> >r;


            if (num.size() < 3)
                return res;
            sort(num.begin(), num.end());

            for (int i = 0; i < num.size() - 2; i ++){
                int j = i+1, k = num.size() - 1;
                while (j < k) {
                    if (num[i] + num[j] + num[k] == 0){
                        vector<int> v;
                        v.push_back(num[i]);
                        v.push_back(num[j]);
                        v.push_back(num[k]);
                        r.insert(v);
                        j++;k--;
                    } else if (num[i] + num[j] + num[k] < 0)
                        j++;
                    else
                        k--;
                }
            }

            res.assign(r.begin(), r.end());
            return res;
        }

        vector<vector<int> > threeSum(vector<int> &num) {
            vector<vector<int> >res;

            if (num.size() < 3)
                return res;

            sort(num.begin(), num.end());
            for (int i = 0; i < num.size() - 2; i ++){
                if (i > 0 && num[i] == num[i-1])
                    continue;

                int j = i+1, k = num.size() - 1;
                while (j < k) {
                    while(k>num.size()-1 && num[k]==num[k+1])
                        k--;
                    if (j >= k) break;
                    while( j != i+1 && j>0 && num[j]==num[j-1])
                        j++;
                    if (j >= k) break;
                    if (num[i] + num[j] + num[k] == 0){
                        vector<int> v;
                        v.push_back(num[i]);
                        v.push_back(num[j]);
                        v.push_back(num[k]);
                        res.push_back(v);
                        j++;k--;
                    } else if (num[i] + num[j] + num[k] < 0)
                        j++;
                    else
                        k--;
                }
            }
            return res;
        }

        int threeSumClosest(vector<int> &num, int target) {
            vector<vector<int> >res;
            int min =  std::numeric_limits<int>::max()/2;
            if (num.size() < 3)
                return 0;

            sort(num.begin(), num.end());
            for (int i = 0; i < num.size() - 2; i ++){
                if (i > 0 && num[i] == num[i-1])
                    continue;
                int j = i+1, k = num.size() - 1;
                int cur = std::numeric_limits<int>::max()/2;
                while (j < k) {
                    while(k>num.size()-1 && num[k]==num[k+1])
                        k--;
                    if (j >= k) break;
                    while( j != i+1 && j>0 && num[j]==num[j-1])
                        j++;
                    if (j >= k) break;

                    if (abs(num[i] + num[j] + num[k] - target) < abs(cur - target))
                        cur = num[i] + num[j] + num[k];

                    if (num[i] + num[j] + num[k] == target){
                        return target;
                    } else if (num[i] + num[j] + num[k] < target)
                        j++;
                    else
                        k--;
                }

                if (abs(cur - target) < abs(min - target))
                    min = cur;
            }
            return min;

        }

        vector<vector<int> > fourSum(vector<int> &num, int target) {
            sort(num.begin(), num.end());
            vector<vector<int> >res;
            set<vector<int> >re;
            map<int, vector<pair<pair<int, int>, pair<int, int> > > > m;
            if (num.size() < 4) return res;
            for (int i = 0; i < num.size()-1; i ++){
                if (i > 0&&num[i] == num[i-1]) continue;
                for (int j = i+1; j < num.size(); j++){
                    if (j != i+1 && num[j] == num[j-1]) continue;
                    m[num[i]+num[j]].push_back(make_pair(make_pair(i, num[i]),
                                                         make_pair(j, num[j])));
                }
            }


            for (auto it = m.begin(); it != m.end(); it++){
                int p1 = it->first;
                
                if (target - p1 < p1) break;
                if (m.find(target-p1) == m.end()) continue;
                
                vector<pair<pair<int, int>, pair<int, int> > > v1 = it->second;
                vector<pair<pair<int, int>, pair<int, int> > > v2 = m[target-p1];

                for (int i = 0; i < v1.size(); i++)
                    for (int j = 0; j < v2.size(); j++){
                        vector<int> v;
                        pair<pair<int, int>, pair<int, int> > l = v1[i];
                        pair<pair<int, int>, pair<int, int> > r = v2[j];

                        if (l.first.first != r.first.first && \
                            l.first.first != r.second.first && \
                            l.second.first != r.first.first && \
                            l.second.first != r.second.first) {
                        
                            v.push_back(l.first.second);
                            v.push_back(l.second.second);
                            v.push_back(r.first.second);
                            v.push_back(r.second.second);

                            sort(v.begin(), v.end());

                            re.insert(v);
                        }
                    }
            }
            res.assign(re.begin(), re.end());
            return res;
        }
};

int main()
{
    /*int A[] = {0,4,0};
      vector<int> v;
      v.assign(A, A+sizeof(A)/sizeof(int));

      Solution S;
      vector<int > r = S.twoSum(v, 0);

      cout <<"result:" << r[0] << "," << r[1] <<endl;
      int A[] = {7,-1,14,-12,-8,7,2,-15,8,8,-8,-14,-4,-5,7,9,11,-4,-15,-6,1,-14,4,3,10,-5,2,1,6,11,2,-2,-5,-7,-6,2,-15,11,-6,8,-4,2,1,-1,4,-6,-15,1,5,-15,10,14,9,-8,-6,4,-6,11,12,-15,7,-1,-9,9,-1,0,-4,-1,-12,-2,14,-9,7,0,-3,-4,1,-2,12,14,-10,0,5,14,-1,14,3,8,10,-8,8,-5,-2,6,-11,12,13,-7,-12,8,6,-13,14,-2,-5,-11,1,3,-6};
      vector<int> v;
      v.assign(A, A+sizeof(A)/sizeof(int));

      Solution S;
      vector<vector<int> > r = S.threeSum(v);

      for (int i = 0; i < r.size(); i++){
      for (int j = 0; j < 3; j++)
      cout << r[i][j] << " ";

      cout <<endl;

      }
    int A[] = {-3,-2,-5,3,-4};
    vector<int> v;
    v.assign(A, A+sizeof(A)/sizeof(int));

    Solution S;
    cout << S.threeSumClosest(v, -1) <<endl;
     */
      int A[] = {1, 0, -1, 0, -2, 2};
      vector<int> v;
      v.assign(A, A+sizeof(A)/sizeof(int));

      Solution S;
      vector<vector<int> > r = S.fourSum(v, 0);

      for (int i = 0; i < r.size(); i++){
      for (int j = 0; j < 4; j++)
          cout << r[i][j] << " ";

      cout <<endl;

      }

    return 0;
}
