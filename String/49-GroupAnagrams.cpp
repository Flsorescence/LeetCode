/**49 Group Anagrams
 * Given an array of strings, group anagrams together.
 * example:
 * Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
 * Output:
 * [
 *   ["ate","eat","tea"],
 *   ["nat","tan"],
 *   ["bat"]
 * ]
 */

class Solution {
public:
    
    bool cmp(char a, char b){ return a < b;}
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        if(strs.empty()) return res;
        map<string, vector<string>> m;
        for(int i = 0; i < strs.size(); i++){
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            m[tmp].push_back(strs[i]);
        }
        for(auto vec: m){
            res.push_back(vec.second);
        }
        return res;
    }
};