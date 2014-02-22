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


       int maxProfit2(vector<int> &prices) {
            
       }

 };

int main()
{
    vector<int> p;
//    p.push_back(6);
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

    Solution S;
    cout << S.maxProfit(p) <<endl;
    cout << S.maxProfit1(p) <<endl;
    cout << S.maxProfit2(p) <<endl;

    return 0;
}
