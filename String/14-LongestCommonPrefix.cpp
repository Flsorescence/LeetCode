/* 14 Longest Common Prefix
 * Write a function to find the longest common prefix string amongst an array of strings.
 * If there is no common prefix, return an empty string "".
 * example:
 * Input: ["flower","flow","flight"]
 * Output: "fl"
 */

//一开始的时候假设第一个字符串是最长公共前缀，然后和每个字符串比较
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return ""; 
        else if(strs.size() == 1) return strs[0];
        
        string res = "";
        for(int i = 0; i < strs[0].length(); i++){
            for(int j = 1; j < strs.size(); j++){
                if(strs[0][i] != strs[j][i]) return res;
            }
            res += strs[0][i];
        }
        return res;
    }
};