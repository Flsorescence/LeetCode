/* 27 Remove Element
 * Given an array nums and a value val, remove all instances of that value in-place and return the new length.
 * Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
 * The order of elements can be changed. It doesn't matter what you leave beyond the new length.
 * example：
 * Given nums = [3,2,2,3], val = 3,
 * Your function should return length = 2, with the first two elements of nums being 2.
 * It doesn't matter what you leave beyond the returned length.
 */

//和26题思路一样，设置一个index变量来存放当前不等于val的数字的下标
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size() == 0 || (nums.size() == 1 && nums[0] == val)) return 0;
        else if(nums.size() == 1) return 1;
        
        int index = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != val){
                nums[index] = nums[i];
                index ++;
            }
        }
        return index;
    }
};