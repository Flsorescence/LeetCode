/**5 Longest Palindromic Substring
 * Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
 * Example 1:
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 */
 
//动态规划 
class Solution {
public:
    string longestPalindrome(string s) {
        int left = 0, right = 0, n = s.length();
        //printf("%d\n", n);
        if(s.size() == 0) return "";
        int flag[n][n];
        memset(flag, 0, sizeof(flag));
        for(int i = s.length() - 2; i >= 0; i--) {
            flag[i][i] = 1;
            for(int j = i + 1; j < n; j++) {
                //printf("%d\n", flag[i][j]);
                if(s[i] == s[j] && (j - i < 3 ||flag[i+1][j-1] == 1)) {
                    
                    flag[i][j] = 1;
                }
                if(flag[i][j] == 1 && right - left < j - i) {
                    left = i; right = j;
                }
                //printf("%c %c %d\n", s[i], s[j], flag[i][j]);
            }
        }
        return s.substr(left, right - left + 1);
    }
};