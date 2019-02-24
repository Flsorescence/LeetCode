/**17 Letter Combinations of a Phone Number
 * Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
 * A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
 * Example:
 * Input: "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 */

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.empty()) return res;
        
        string alpha[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        letter(res, alpha, "", 0, digits);
        return res;
    }
    
    void letter(vector<string>& res, string alpha[], string tmp, int level, string digits){
        if(level == digits.size()) {res.push_back(tmp); return;}
        string a = alpha[digits[level]-'0'];
        for(int i = 0; i < a.size(); i++){
            letter(res, alpha, tmp+a[i], level+1, digits);
        }
    }
};