/**77 Combinations
 * Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
 * Example:
 * Input: n = 4, k = 2
 * Output:
 * [
 *   [2,4],
 *   [3,4],
 *   [2,3],
 *   [1,2],
 *   [1,3],
 *   [1,4],
 * ]
 */

//限制长度并且限制递增的全排列问题
 
class Solution {
public:
    vector<vector<int>> res;
    void generateCombined(int n, int k, int start, vector<int> tmp){
        if(tmp.size() == k){
            res.push_back(tmp);
            return;
        }
        for(int i = start; i <= n; i++){
            tmp.push_back(i);
            generateCombined(n, k, i + 1, tmp);
            tmp.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        if(n <= 0 || k <= 0 || k > n)
            return res;
        vector<int> tmp;
        generateCombined(n, k, 1, tmp);
        return res;
    }
};