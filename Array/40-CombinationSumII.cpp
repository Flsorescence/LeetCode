/* 40 Combination Sum II
 * Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.
 * Each number in candidates may only be used once in the combination.
 * Notes: 1.All numbers (including target) will be positive integers. 2.The solution set must not contain duplicate combinations.
 * example:
 * Input: candidates = [10,1,2,7,6,1,5], target = 8,
 * A solution set is:
 * [
 *   [1, 7],
 *   [1, 2, 5],
 *   [2, 6],
 *   [1, 1, 6]
 * ]
 */

//在39题的基础上做一些改动
class Solution {
public:
    void compute(int start, int target, vector<int>& tmp, vector<int>& candidates, vector<vector<int>>& ans){
        int len = candidates.size();
        candidates.push_back(INT_MAX);
        
        for(int i = start; i <= len; i++){
            if(i > start && candidates[i] == candidates[i-1]) continue; 
            if(target > 0){
                tmp.push_back(candidates[i]);
                compute(i+1, target - candidates[i], tmp, candidates, ans);
                tmp.pop_back();
            }else if(target < 0){
                return;
            }else{
                ans.push_back(tmp);
                return;
            }
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> tmp;
    
        sort(candidates.begin(), candidates.end());
        compute(0, target, tmp, candidates, ans);
        
        return ans;
    }
};