/* 16 3Sum Closest
 * Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. 
 * You may assume that each input would have exactly one solution.
 * example:
 * Given array nums = [-1, 2, 1, -4], and target = 1.
 * The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 */
 
//这一题是在3Sum的基础上进行改进，总体解决思路一致
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int j, k;
        int dis = INT_MAX, res = INT_MAX;
        for(int i = 0; i < nums.size() - 2; i++){
            j = i + 1; k = nums.size() - 1;
            int tmp = target - nums[i];
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(dis > abs(target - sum)) {
                    res = sum;
                    dis = abs(target - sum);
                }
                if(tmp <= nums[j] + nums[k]) k--;
                else if(tmp > nums[j] + nums[k]) j++;
            }
        }
        return res;
    }
};