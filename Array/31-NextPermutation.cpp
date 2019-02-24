/**31 Next Permutation
 * Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
 * If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
 * The replacement must be in-place and use only constant extra memory.
 * Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 */

//从后往前遍历，找到第一个当前位比前一位大的数字，从当前位到最后按从小到大排序，然后找到第一个比前一位大的数字，将两个数字进行交换
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int flag = 0;
        for(int i = n - 1; i > 0; i--){
            if(nums[i] > nums[i-1]){
                sort(nums.begin()+i, nums.end());
                for(int j = i; j < n; j++){
                    if(nums[j] > nums[i-1]){
                        int tmp = nums[j];
                        nums[j] = nums[i-1];
                        nums[i-1] = tmp;
                        flag = 1;
                        break;
                    }
                }
                if(flag == 1) break;
            }
        }
        if(flag == 0) sort(nums.begin(), nums.end());
    }
};