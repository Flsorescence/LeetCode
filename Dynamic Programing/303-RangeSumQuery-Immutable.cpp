/**303 Range Sum Query - Immutable
 * Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.
 * Example:
 * Given nums = [-2, 0, 3, -5, 2, -1]
 * sumRange(0, 2) -> 1
 * sumRange(2, 5) -> -1
 * sumRange(0, 5) -> -3
 * Note:
 * You may assume that the array does not change.
 * There are many calls to sumRange function.
 */
 
class NumArray {
public:
    vector<int> arr;
    NumArray(vector<int>& nums) {
        arr.push_back(0);
        for(int i = 1; i < nums.size() + 1; i++){
            arr.push_back(arr[i-1] + nums[i-1]);
        }
    }
    
    int sumRange(int i, int j) {
        return arr[j+1] - arr[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */