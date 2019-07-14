/**746 Min Cost Climbing Stairs
 * On a staircase, the i-th step has some non-negative cost cost[i] assigned (0 indexed).
 * Once you pay the cost, you can either climb one or two steps. You need to find minimum cost to reach the top of the floor, and you can either start from the step with index 0, or the step with index 1.
 * Example 1:
 * Input: cost = [10, 15, 20]
 * Output: 15
 * Explanation: Cheapest is start on cost[1], pay that cost and go to the top.
 * Example 2:
 * Input: cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
 * Output: 6
 * Explanation: Cheapest is start on cost[0], and only step on 1s, skipping cost[3].
 * Note:
 * cost will have a length in the range [2, 1000].
 * Every cost[i] will be an integer in the range [0, 999].
 */

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int len = cost.size();
        if(len == 0) return 0;
        else if(len == 1) return cost[0];
        else if(len == 2) return min(cost[0], cost[1]);
        
        vector<int> c1(len, 0), c2(len-1, 0);
        c1 = cost;
        for(int i = 1; i < len; i++)
            c2[i-1] = cost[i];
        
        return min(minCost(c1), minCost(c2));
    }
    
    int minCost(vector<int>& cost){
        int len = cost.size();
        int opt[len + 1] = {0};
        opt[1] = cost[0];
        for(int i = 2; i < len + 1; i++){
            opt[i] = min(opt[i-2] + cost[i-2], opt[i-1] + cost[i-1]);
        }
        return opt[len];
    }
};