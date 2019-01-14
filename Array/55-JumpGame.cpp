/* 55 Jump Game
 * Given an array of non-negative integers, you are initially positioned at the first index of the array.
 * Each element in the array represents your maximum jump length at that position.
 * Determine if you are able to reach the last index.
 * example:
 * Input: [2,3,1,1,4]
 * Output: true
 * Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
 */
 
//贪心算法，每次都取能跳的最大步长
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int target = nums.size() - 1;
        int reach = 0;
        for(int i = 0; i < nums.size() - 1 && i <= reach; i++){
            reach = max(reach, nums[i] + i);
        }
        if(reach >= target) return true;
        else return false;
    }
};
 