/* 34 Find First and Last Position of Element in Sorted Array
 * Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * If the target is not found in the array, return [-1, -1].
 * example：
 * Input: nums = [5,7,7,8,8,10], target = 8
 * Output: [3,4]
 */
 
//二分查找，找到目标值后，从当前位置向前和向后遍历，直到不等于目标值，记录下标，即为范围
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        if(nums.size() == 0) return res;
        if(nums[0] > target || nums[nums.size() - 1] < target) return res;
        int l = 0, r = nums.size() - 1;
        while(l <= r){
            int mid = (l + r) / 2;
            if(nums[mid] == target){
                int i = mid, j = mid;
                while(nums[i] == target && i >= 0) i--;
                while(nums[j] == target && j <= nums.size() - 1) j++;
                res[0] = i + 1;
                res[1] = j - 1;
                break;
            }else if(nums[mid] > target) r = mid - 1;
            else l = mid + 1;
        }
        return res;
    }
};