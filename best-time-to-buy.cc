#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;
class Solution {
    public:
        int maxProfit(vector<int> &prices) {
            int max = 0;
            if (prices.size() == 1)
                return 0;
            if (prices.size() == 0)
                return 0;

            if (prices.size() == 2)
                if (prices[0] < prices[1])
                    return prices[1] - prices[0];
                else 
                    return 0;

            int mi = 0;

            for (int i = 1; i < prices.size(); i++) {
                if (prices[i] > prices[mi] && prices[i] - prices[mi] > max) {
                    max = prices[i] - prices[mi];
                }

                if (prices[i] < prices[mi]) {
                    mi = i;
                }
            }

            return max;
        }
        int maxProfit1(vector<int> &prices) {
            int max = 0;
            int sum = 0;
            if (prices.size() == 1)
                return 0;
            if (prices.size() == 0)
                return 0;

            if (prices.size() == 2)
                if (prices[0] < prices[1])
                    return prices[1] - prices[0];
                else 
                    return 0;

            int mi = 0;

            for (int i = 1; i < prices.size(); i++) {
                if (prices[i] > prices[mi] && prices[i] - prices[mi] > max) {
                    max = prices[i] - prices[mi];
                }

                if (prices[i] < prices[i - 1]) {
                    mi = i;
                    sum += max;
                    max = 0;
                }
            }

            sum += max;

            return sum;
        }
        /* Version 1
           int maxProfit2(vector<int> &prices) {
           int max = 0, max1 = 0, max2 = 0;
           int sum = 0;
           if (prices.size() == 1)
           return 0;
           if (prices.size() == 0)
           return 0;

           if (prices.size() == 2)
           if (prices[0] < prices[1])
           return prices[1] - prices[0];
           else 
           return 0;

           int mi = 0;

           for (int i = 1; i < prices.size(); i++) {
           if (prices[i] > prices[mi] && prices[i] - prices[mi] > max) {
           max = prices[i] - prices[mi];
           }

           if (prices[i] < prices[mi]) {
           mi = i;
           if (max2 < max)
           max2 = max;
           if (max1 < max2) {
           int tmp;
           tmp = max1;
           max1 = max2;
           max2 = tmp;
           }
           max = 0;
           }
           }

           if (max2 < max)
           max2 = max;

           if (max1 < max2) {
           int tmp;
           tmp = max1;
           max1 = max2;
           max2 = tmp;
           }

           sum += max;

           return max1 + max2;
           } */
/*
        int _maxProfit2(int prices[], int n) {
            int max = 0;
            if (n == 1 && n == 0)
                return 0;
            if (n == 2)
                if (prices[0] < prices[1])
                    return prices[1] - prices[0];
                else 
                    return 0;
            int mi = 0;
            for (int i = 1; i < n; i++) {
                if (prices[i] > prices[mi] && prices[i] - prices[mi] > max) {
                    max = prices[i] - prices[mi];
                }
                if (prices[i] < prices[mi]) {
                    mi = i;
                }
            }
            return max;
        }
        int maxProfit2(vector<int> &prices) {
            int *A, n;
            int i;
            int max = 0;

            n = prices.size();
            A = (int *) malloc ( sizeof (int) * n);
            
            for (i = 0; i < n; i++)
                A[i] = prices[i];

            for (i = 0; i <= n; i ++){
                int t = _maxProfit2(A, i);
                
                t +=_maxProfit2(A + i, n - i);
                if (t > max)
                    max = t;
            }
            free(A);
            return max;
        } */


        int maxProfit2(vector<int> &prices) {
            int max = 0;
            int n = prices.size();
            int *p;
            int *q;
            int *max_left;
            int *max_right;

            if (n == 1 || n == 0)
                return 0;

            if (prices.size() == 2)
                if (prices[0] < prices[1])
                    return prices[1] - prices[0];
                else 
                    return 0;

            p = (int *) malloc ( sizeof (int) * (n+2));
            q = (int *) malloc ( sizeof (int) * (n+2));
            max_left = p;
            max_right = q;

            max_left[0] = 0;
            max_right[0] = 0;
            max_left++;
            max_right++;
            max_left[n] = 0;
            max_right[n] = 0;
            
            for (int i = 0; i <= n; i++) {
                max_left[i] = 0;
                max_right[i] = 0;
            }

            int mi = 0;

            for (int i = 1; i < prices.size(); i++) {
                if (prices[i] > prices[mi] && prices[i] - prices[mi] > max) {
                    max = prices[i] - prices[mi];
                }

                if (prices[i] < prices[mi]) {
                    mi = i;
                }
                max_left[i] = max;
            }

            mi = n - 1;
            max = 0;
            for (int i = n - 2; i >= 0; i--) {
                if (prices[i] < prices[mi] && prices[mi] - prices[i] > max) {
                    max = prices[mi] - prices[i];
                }

                if (prices[i] > prices[mi]) {
                    mi = i;
                }

                max_right[i] = max;
            }

            max = 0;

            for (int i = -1; i < n; i ++){
                if (max_left[i] + max_right[i+1] > max)
                    max = max_left[i] + max_right[i+1];
            }

            free(p);
            free(q);

            return max;   
        }

};

int main()
{
    vector<int> p;

    p.push_back(1);
    p.push_back(2);
    p.push_back(4);
    p.push_back(2);
    p.push_back(5);
    p.push_back(7);
    p.push_back(2);
    p.push_back(4);
    p.push_back(9);
    p.push_back(0);
    p.push_back(9);
/*
    p.push_back(1);
    p.push_back(3);
    p.push_back(2);
    p.push_back(5);
    p.push_back(3);
    p.push_back(8);
    */

/*
    p.push_back(3);
    p.push_back(2);
    p.push_back(6);
    p.push_back(5);
    p.push_back(0);
    p.push_back(3);
    */
/*
    p.push_back(2);
    p.push_back(1);
    p.push_back(2);
    p.push_back(0);
    p.push_back(1);
*/

    Solution S;
    cout << S.maxProfit(p) <<endl;
    cout << S.maxProfit1(p) <<endl;
    cout << S.maxProfit2(p) <<endl;

    return 0;
}
