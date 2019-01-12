/* 26 Remove Duplicates from Sorted Array
 * Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.
 * Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
 * example：
 * Given nums = [1,1,2],
 * Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
 * It doesn't matter what you leave beyond the returned length.
 */

//设置一个变量index记录当前不重复数字的下标，从index+1开始遍历数组，如果i位置出现的数字和index位置的数字相同，说明该数字重复出现，不予处理，否则将该数字放在index+1的位置上

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int index = 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] != nums[index]){
                index ++;
                nums[index] = nums[i];
            }
        }
        return index + 1; //index是下标，是从0开始的，所以总数是index+1
    }
};