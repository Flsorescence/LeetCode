/**3 Longest Substring Without Repeating Characters
 * Given a string, find the length of the longest substring without repeating characters.
 * Example 1:
 * Input: "abcabcbb"
 * Output: 3 
 * Explanation: The answer is "abc", with the length of 3. 
 */
 
//维护一个滑动窗口和set（用来记录窗口中的字符），窗口内都是没有重复的字符，把右边的字符依次加入窗口，判断所加字符是否已经出现过，如果出现过就移动窗口的左边界，直到删除set中的重复字符，否则直接加入窗口
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> t;
        int res = 0, left = 0, right = 0;
        while (right < s.size()) {
            if (t.find(s[right]) == t.end()) {
                t.insert(s[right++]);
                res = max(res, (int)t.size());
            }  else {
                t.erase(s[left++]);
            }
        }
        return res;
    }
};