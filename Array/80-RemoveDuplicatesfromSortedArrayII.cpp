/* 80 Remove Duplicates from Sorted Array II
 * Given a sorted array nums, remove the duplicates in-place such that duplicates appeared at most twice and return the new length.
 * Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
 * Example:
 * Given nums = [1,1,1,2,2,3],
 * Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.
 * It doesn't matter what you leave beyond the returned length.
 */

//设置一个pos位，将当前位置i与pos前两位的元素比较是否相等，如果不相等，将pos位设为下标i的值，否则继续寻找下一个不相等的下标i
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if(len <= 2) return len;
        int pos = 2;
        for(int i = 2; i < len; i++){
            if(nums[i] != nums[pos-2])
                nums[pos++] = nums[i];
        }
        return pos;
    }
};