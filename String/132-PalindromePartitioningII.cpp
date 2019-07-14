/**132 Palindrome Partitioning II
 * Given a string s, partition s such that every substring of the partition is a palindrome.
 * Return the minimum cuts needed for a palindrome partitioning of s.
 * Example:
 * Input: "aab"
 * Output: 1
 * Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
 */
 
// 动态规划
// 求最小切分次数，即有多少个最长回文子串
class Solution {
public:
    int minCut(string s) {
        int len = s.size();
        if(len == 0) return 0;
        int flag[len][len] = {0};
        int cut[len];
        for(int i = 0; i < len; i++){
            cut[i] = i;
            for(int j = 0; j <= i; j++){
                if(s[i] == s[j] && (i - j <= 1 || flag[j+1][i-1] == 1)){
                    flag[j][i] = 1;
                    if(j == 0)
                        cut[i] = 0;
                    else
                        cut[i] = min(cut[i], cut[j-1] + 1);
                }
            }
        }
        return cut[len-1];
    }
};