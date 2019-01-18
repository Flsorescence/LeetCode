/* 78 Subsets
 * Given a set of distinct integers, nums, return all possible subsets (the power set).
 * Note: The solution set must not contain duplicate subsets.
 * example
 * Input: nums = [1,2,3]
 * Output:
 * [
 *   [3],
 *   [1],
 *   [2],
 *   [1,2,3],
 *   [1,3],
 *   [2,3],
 *   [1,2],
 *   []
 * ]
 */


//解法一，bitmap 
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int elem_num = nums.size();
        int subset_num = pow (2, elem_num);
        vector<vector<int>> subset_set(subset_num, vector<int>());

        for (int i = 0; i < elem_num; i++)
            for (int j = 0; j < subset_num; j++)
                if ((j >> i) & 1)
                    subset_set[j].push_back(nums[i]);

        return subset_set;
    }
};

//解法二，回溯法
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        sort(nums.begin(), nums.end());
        getSubsets(nums, 0, tmp, res);
        return res;
    }
    
    void getSubsets(vector<int>& nums, int p, vector<int>& tmp, vector<vector<int>>& res){
        res.push_back(tmp);
        for(int i = p; i < nums.size(); i++){
            tmp.push_back(nums[i]);
            getSubsets(nums, i+1, tmp, res);
            tmp.pop_back();
        }
    }
};


//解法三
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > res(1);
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            int size = res.size();
            for (int j = 0; j < size; ++j) {
                res.push_back(res[j]);
                res.back().push_back(nums[i]);
            }
        }
        return res;
    }
};