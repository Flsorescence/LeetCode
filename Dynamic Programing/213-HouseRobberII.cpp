/**213 House Robber II 
 * You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
 * Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
 * Example 1:
 * Input: [2,3,2]
 * Output: 3
 * Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2),
 *              because they are adjacent houses.
 */

// 第一种是：第一个房子到倒数第二个房子， 第二种是：第二个房子到最后一个房子
class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return 0;
        else if(len == 1) return nums[0];
        else if(len == 2) return max(nums[0], nums[1]);
        
        vector<int> cycle1(len-1, 0), cycle2(len-1, 0);
        for(int i = 0; i < len-1; i++) cycle1[i] = nums[i];
        for(int i = 1; i < len; i++) cycle2[i-1] = nums[i];
        return max(robber(cycle1), robber(cycle2));
    }
    
    int robber(vector<int>& nums){
        int len = nums.size();
        int opt[len] = {0};
        opt[0] = nums[0];
        opt[1] = max(nums[0], nums[1]);
        for(int i = 2; i < len; i++){
            opt[i] = max(nums[i] + opt[i-2], opt[i-1]);
        }
        return opt[len-1];
    }
};