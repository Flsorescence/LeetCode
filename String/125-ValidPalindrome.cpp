/**125 Valid Palindrome
 * Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
 * Note: For the purpose of this problem, we define empty string as valid palindrome.
 * Example 1:
 * Input: "A man, a plan, a canal: Panama"
 * Output: true
 * Example 2:
 * Input: "race a car"
 * Output: false
 */
 
// 只考虑字母和数字，不考虑特数符号，并且不区分大小写
class Solution {
public:
    bool isPalindrome(string s) {
        if(s.size() == 0 || s.size() == 1) return true;
        int len = s.size();
        int i = 0, j = len - 1;
        while(i < j){
            if(!((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))){
                i++;
                continue;
            }
            if(!((s[j] >= 'A' && s[j] <= 'Z') || (s[j] >= 'a' && s[j] <= 'z') || (s[j] >= '0' && s[j] <= '9'))){
                j--;
                continue;
            }
            
            if(tolower(s[i]) != tolower(s[j])) 
                return false;
            i++; j--;
        }
        return true;
    }
};