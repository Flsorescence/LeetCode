/**28 Implement strStr()
 *
 */

//暴力法 
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.size() < needle.size()) return -1;
        if(needle.size() == 0) return 0;
        for(int i = 0; i < haystack.size(); i++){
            if(needle[0] == haystack[i]){
                int flag = 1;
                for(int j = 1, k = i+1; j < needle.size(); j++, k++){
                    if(needle[j] != haystack[k]){
                        flag = 0;
                        break;
                    }
                }
                if(flag == 1) return i;
            }
        }
        return -1;
    }
};