/* 33 Search in Rotated Sorted Array
 * Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
 * (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
 * You are given a target value to search. If found in the array return its index, otherwise return -1.
 * You may assume no duplicate exists in the array.
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * example:
 * Input: nums = [4,5,6,7,0,1,2], target = 0
 * Output: 4
 */
 
//要求时间复杂度为log(m+n)，所以考虑二分查找
//0　　1　　2　　 4　　5　　6　　7
//7　　0　　1　　 2　　4　　5　　6
//6　　7　　0　　 1　　2　　4　　5
//5　　6　　7　　 0　　1　　2　　4
//4　　5　　6　　7　　0　　1　　2
//2　　4　　5　　6　　7　　0　　1
//1　　2　　4　　5　　6　　7　　0
//如果中间的数小于最右边的数，则右半段是有序的，若中间数大于最右边数，则左半段是有序的，
//我们只要在有序的半段里用首尾两个数组来判断目标值是否在这一区域内，这样就可以确定保留哪半边了
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0) return -1;
        int left = 0, right = nums.size() - 1;
        while(left <= right){
            int mid = (left + right) / 2;
            if(target == nums[mid]) return mid;
            if(nums[mid] < nums[right]){
                if(nums[mid] < target && nums[right] >= target) left = mid + 1;
                else right = mid - 1;
            }else{
                if(nums[mid] > target && nums[left] <= target) right = mid - 1;
                else left = mid + 1;
            }
        }
        return -1;
    }
};