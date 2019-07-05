/**131 Palindrome Partitioning
 * Given a string s, partition s such that every substring of the partition is a palindrome.
 * Return all possible palindrome partitioning of s.
 * Example:
 * Input: "aab"
 * Output:
 * [
 *   ["aa","b"],
 *   ["a","a","b"]
 * ]
 */
 
// DFS+回溯 
// 遇到要求所有组合、可能、排列等解集的题目，一般都是DFS + backtracking
class Solution {
public:
    
    bool isPalindrome(string s){
        int len = s.length();
        for(int i = 0; i <= len/2; i++){
            if(s[i] != s[len-1-i]) return false;
        }
        return true;
    }
    
    void dfs(vector<vector<string>> &res, vector<string> &tmp, int n, string s){
        if(n == s.length()){
            res.push_back(tmp);
            return;
        }
        
        for(int i = n; i < s.length(); i++){
            if(isPalindrome(s.substr(n, i-n+1))){
                tmp.push_back(s.substr(n, i-n+1));
                dfs(res, tmp, i+1, s);
                tmp.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        if(s.length() == 0) return res;
        vector<string> tmp;
        dfs(res, tmp, 0, s);
        return res;
    }
};