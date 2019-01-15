/* 41 First Missing Positive
 * Given an unsorted integer array, find the smallest missing positive integer.
 * example:
 * Input: [1,2,0]
 * Output: 3
 */

//数组中可能有重复值，一开始没考虑到
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if(nums.size() == 0 || (nums[0] > 0 && nums[0] != 1)||nums[nums.size()-1] <= 0) return 1;
        int res = 1, i = 0;
        while(nums[i] <= 0) i++;
        for(; i < nums.size(); i++){
            if(nums[i] != res) {
                if(nums[i] == nums[i-1]) continue;
                else return res;
            }
            else res++;
        }
        return res;
    }
};