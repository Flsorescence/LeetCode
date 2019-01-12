/* 18 4Sum
 * Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? 
 * Find all unique quadruplets in the array which gives the sum of target.
 * Note: The solution set must not contain duplicate quadruplets.
 * example:
 * Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
 * A solution set is:
 * [
 *   [-1,  0, 0, 1],
 *   [-2, -1, 1, 2],
 *   [-2,  0, 0, 2]
 * ]
 */
 
//在3个数求和的基础上，再嵌套一层循环，时间复杂度是O（n^3)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        set<vector<int>> s;
        if(nums.size() < 4) return res;
        sort(nums.begin(), nums.end());
        int l, r;
        for(int i = 0; i < nums.size() - 3; i++){
            for(int j = i+1; j < nums.size() - 2; j++){
                l = j + 1; r = nums.size() - 1;
                if(nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target) break;
                if(nums[r] + nums[r-1] + nums[r-2] + nums[r-3] < target) break;
                while(l < r){
                    if(nums[i] + nums[j] + nums[l] + nums[r] < target) l++;
                    else if(nums[i] + nums[j] + nums[l] + nums[r] > target) r--;
                    else{
                        int len = s.size();
                        s.insert({nums[i], nums[j], nums[l], nums[r]});
                        if(s.size() > len) res.push_back({nums[i], nums[j], nums[l], nums[r]});
                        l++; r--;
                    }
                }
            }
        }
        return res;
    }
};