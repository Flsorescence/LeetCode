/* 39 Combination Sum
 * Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.
 * The same repeated number may be chosen from candidates unlimited number of times.
 * Notes: 1.All numbers (including target) will be positive integers. 2.The solution set must not contain duplicate combinations.
 * example:
 * Input: candidates = [2,3,6,7], target = 7,
 * A solution set is:
 * [
 *   [7],
 *   [2,2,3]
 * ]
 */
 
//回溯法
class Solution {
public:
    void compute(int start, int target, vector<int>& tmp, vector<int>& candidates, vector<vector<int>>& ans){
        int len = candidates.size();
        for(int i = start; i < len; i++){
            if(target > 0){
                tmp.push_back(candidates[i]);
                compute(i, target - candidates[i], tmp, candidates, ans);
                tmp.pop_back();
            }else if(target < 0){
                return;
            }else{
                ans.push_back(tmp);
                return;
            }
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> tmp;
        
        sort(candidates.begin(), candidates.end());
        compute(0, target, tmp, candidates, ans);
        
        return ans;
    }
};