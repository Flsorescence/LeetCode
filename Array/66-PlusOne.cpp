/* 66 Plus One
 * Given a non-empty array of digits representing a non-negative integer, plus one to the integer.
 * The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.
 * You may assume the integer does not contain any leading zero, except the number 0 itself.
 * example:
 * Input: [1,2,3]
 * Output: [1,2,4]
 * Explanation: The array represents the integer 123.
 */

 
//需要考虑进位的情况，已经第一位进位，数组长度+1 
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        int c = 0;
        digits[len - 1] += 1;
        if(digits[len-1] >= 10){
            digits[len-1] -= 10;
            c = 1;
        }
        for(int i = len-2; i >= 0; i--){
            digits[i] = digits[i] + c;
            if(digits[i] >= 10){
                digits[i] -= 10;
                c = 1;
            }else c = 0;
        }
        if(c == 1){
            vector<int> res;
            res.push_back(1);
            for(int i = 0; i < len; i++)
                res.push_back(digits[i]);
            return res;
        }
        return digits;
    }
};