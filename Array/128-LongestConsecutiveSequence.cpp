/**128 Longest Consecutive Sequence
 * Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
 * Your algorithm should run in O(n) complexity.
 * Example:
 * Input: [100, 4, 200, 1, 3, 2]
 * Output: 4
 * Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
 */
 
// HashSet 
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int ans = 0;
        for(int num: nums){
            int tmp = 1;
            if(!s.count(num-1)){
                while(s.count(++num))
                    tmp += 1;
                ans = max(ans, tmp);
            }
        }
        return ans;
    }
};

// 排序
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int res = 1;
        sort(nums.begin(), nums.end());
        int tmp = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] - nums[i-1] == 0)
                continue;
            if(nums[i] - nums[i-1] == 1)
                tmp += 1;
            else{
                res = max(res, tmp);
                tmp = 1;
            }
        }
        res = max(res, tmp);
        return res;
    }
};