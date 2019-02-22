/**121 Best Time to Buy and Sell Stock
 * Say you have an array for which the ith element is the price of a given stock on day i.
 * If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.
 * Note that you cannot sell a stock before you buy one.
 * Example 1:
 * Input: [7,1,5,3,6,4]
 * Output: 5
 * Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5. Not 7-1 = 6, as selling price needs to be larger than buying price.
 */

//暴力法，求每一个时间段买入的收益，再求最大收益
class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        vector<int> profit(prices.size(), 0);
        int max = 0;
        for(int i = 0; i < prices.size(); i++){
            for(int j = i + 1; j < prices.size(); j++){
                int p = prices[j] - prices[i];
                if(p > profit[i]) profit[i] = p;
            }
            if(profit[i] > max) max = profit[i];
        }
        
        return max;
    }
};


class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 0) return 0;
        
        int m = prices[0], profit = 0;
        for(int i = 1; i < n; i++){
            if(prices[i] < m) m = prices[i];
            else
                profit = max(profit, prices[i] - m);
        }
        return profit;
    }
};