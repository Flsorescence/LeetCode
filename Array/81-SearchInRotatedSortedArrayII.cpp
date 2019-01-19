/* 81 Search in Rotated Sorted Array II
 * Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
 * (i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).
 * You are given a target value to search. If found in the array return true, otherwise return false.
 * Example:
 * Input: nums = [2,5,6,0,0,1,2], target = 0
 * Output: true
 */

//因为有重复元素，所以需要在原来的基础上判断以下nums[mid]==nums[r]的情况，这种情况将r--，去掉重复元素再尝试
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.size() == 0) return false;
        int l = 0, r = nums.size()-1;
        while(l <= r){
            int mid  = (l + r) / 2;
            if(nums[mid] == target) return true;
            if(nums[mid] < nums[r]){
                if(nums[mid] < target && nums[r] >= target) l = mid + 1;
                else r = mid - 1;
            }
            else if(nums[mid] > nums[r]){
                if(nums[mid] > target && nums[l] <= target) r = mid - 1;
                else l = mid + 1;
            }else r--;
        }
        return false;
    }
};