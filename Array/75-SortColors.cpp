/* 75 Sort Colors
 * Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white and blue.
 * Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
 * Note: You are not suppose to use the library's sort function for this problem.
 * example:
 * Input: [2,0,2,1,1,0]
 * Output: [0,0,1,1,2,2]
 */

 
//借鉴大神的代码，实在是太漂亮了(★ ω ★)
//基本思想是设立三个变量i,j,k，分别表示最后一个0、最后一个1、最后一个2的下标，循环更新下标
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = -1, j = -1, k = -1;
        for(int m = 0; m < nums.size(); m++){
            if(nums[m] == 0){
                nums[++k] = 2;
                nums[++j] = 1;
                nums[++i] = 0;
            }else if(nums[m] == 1){
                nums[++k] = 2;
                nums[++j] = 1;
            }else if(nums[m] == 2){
                nums[++k] = 2;
            }
        }
    }
};