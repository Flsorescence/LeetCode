/**164 Maximum Gap
 * Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
 * Return 0 if the array contains less than 2 elements.
 * Example 1:
 * Input: [3,6,9,1]
 * Output: 3
 *Explanation: The sorted form of the array is [1,3,6,9], either (3,6) or (6,9) has the maximum difference 3.
 */
 
//桶排序
class Solution {
public:
    long long mul(long long x, long long y){
        return x * y;
    }
    
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return 0;
        sort(nums.begin(), nums.end());
        if(nums[n-1] - nums[0] == 0) return 0;
        
        int biggest[n+1], smallest[n+1];
        memset(biggest, -1, sizeof(biggest));
        memset(smallest, -1, sizeof(smallest));
        
        for(int i = 0; i < n; i++){
            long long tmp = mul(nums[i] - nums[0], n + 1);
            tmp = int(tmp / (nums[n-1] - nums[0]));
            if(tmp > n) tmp = n;
            biggest[tmp] = biggest[tmp] == -1? nums[i]: max(nums[i], biggest[tmp]);
            smallest[tmp] = smallest[tmp] == -1? nums[i]: min(nums[i], smallest[tmp]);
        }
        
        int gap = 0, curMax = biggest[0];
        for(int i = 1; i < n + 1; i++){
            if(smallest[i] != -1) {
                gap = max(smallest[i] - curMax, gap);
                curMax = biggest[i];
            }
        }
        return gap;
    }
};