/* 35 Search Insert Position
 * Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
 * You may assume no duplicates in the array.
 * example：
 * [1,3,5,6], 5
 * 2
 */

//最简单粗暴的解法
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] >= target) return i;
        }
        return nums.size();
    }
};

//可以使用二分查找缩短程序运行时间