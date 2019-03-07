/**22. Generate Parentheses
 * Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 * For example, given n = 3, a solution set is:
 * [
 *   "((()))",
 *   "(()())",
 *   "(())()",
 *   "()(())",
 *   "()()()"
 * ]
 */
 
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generate("", res, n, n);
        return res;
    }
    
    void generate(string substring, vector<string> &res, int left, int right) {
        if(left == 0 && right == 0){
            res.push_back(substring);
            return;
        }
        if(left > 0) generate(substring + "(", res, left-1, right);
        if(right > left) generate(substring + ")", res, left, right-1);
    }
};