/**152 Maximum Product Subarray
 * Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.
 * Example 1:
 * Input: [2,3,-2,4]
 * Output: 6
 * Explanation: [2,3] has the largest product 6.
 */
 
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxp = nums[0];
        int minp = nums[0];
        int res = nums[0];
        
        for(int i = 1; i < nums.size(); i++) {
            int t1 = maxp * nums[i];
            int t2 = minp * nums[i];
            maxp = max(max(t1, t2), nums[i]);
            minp = min(min(t1, t2), nums[i]);
            res = max(maxp, res);
        }
        return res;
    }
};