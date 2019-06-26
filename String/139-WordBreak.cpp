/**139 Word Break
 * Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.
 * Note:
 * The same word in the dictionary may be reused multiple times in the segmentation.
 * You may assume the dictionary does not contain duplicate words.
 * Example 1:
 * Input: s = "leetcode", wordDict = ["leet", "code"]
 * Output: true
 * Explanation: Return true because "leetcode" can be segmented as "leet code".
 */
 
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(s.empty()) return false;
        vector<int> dp(s.size()+1, 0);
        dp[0] = 1;
        for(int i = 0; i < s.size(); i++){
            for(int j = 0; j <= i; j++){
                if(dp[j] == 1){
                    string tmp = s.substr(j, i - j + 1);
                    if(find(wordDict.begin(), wordDict.end(), tmp) != wordDict.end()){
                        if(i + 1 < dp.size()){
                            dp[i+1] = 1;
                            break;
                        }
                    }
                }
            }
        }
        if(dp[s.size()] == 1) return true;
        else  return false;
    }
};