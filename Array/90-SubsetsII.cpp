/**90 Subsets II
 * Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).
 * Note: The solution set must not contain duplicate subsets.
 * Example:
 * Input: [1,2,2]
 * Output:
 * [
 *   [2],
 *   [1],
 *   [1,2,2],
 *   [2,2],
 *   [1,2],
 *   []
 * ]
 */

//在subsets的基础上，维护一个set数组，每次把tmp添加进res之前都判断一下是否已经存在，不存在再加入 
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        set<vector<int>> s;
        sort(nums.begin(), nums.end());
        getSub(nums, res, tmp, s, 0);
        return res;
    }
    
    void getSub(vector<int>& nums, vector<vector<int>>& res, vector<int>& tmp, set<vector<int>>& s, int p) {
        if(s.count(tmp) == 0)  res.push_back(tmp);
        s.insert(tmp);
        for(int i = p; i < nums.size(); i++){
            tmp.push_back(nums[i]);
            getSub(nums, res, tmp, s, i+1);
            tmp.pop_back();
        }
    }
};