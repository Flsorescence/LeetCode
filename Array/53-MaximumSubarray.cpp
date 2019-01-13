/* 53 Maximum Subarray
 * Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
 * example:
 * Input: [-2,1,-3,4,-1,2,1,-5,4],
 * Output: 6
 */

//解法一，动态规划，时间复杂度O(n)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = 0, maxn = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            if(ans < 0) ans = 0;
            ans += nums[i];
            maxn = max(maxn, ans);
        }
        return maxn;
    }
};

//解法二，分治法
class Solution {
public:
    int maxSubArray(vector<int>& nums) {  
        return divide(nums, 0, nums.size()-1);
    }  
    
    int divide(vector<int>& nums, int l, int r) {
        if(l == r)  return nums[l];
        if(l == r-1) return max(nums[l], max(nums[r], nums[l]+nums[r]));
        
        int mid = (l+r)>>1;
        int lret = divide(nums, l, mid-1);
        int rret = divide(nums, mid+1, r);
        
        int mret = nums[mid];
        int sum = mret;
        for(int i = mid-1; i >= l ; i --) {
            sum += nums[i];
        //    if(sum < 0) sum = 0;
            mret = max(mret, sum);
        }
        sum = mret;    //保存已经计算过的左边的最大子序和
        for(int i = mid+1; i <= r ; i ++) {
            sum += nums[i];
        //    if(sum < 0) sum = 0;
            mret = max(mret, sum);
        }
        
        return max(lret, max(rret, mret));
    }
};