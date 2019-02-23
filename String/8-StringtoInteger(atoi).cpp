/**8 String to Integer (atoi)
 * Implement atoi which converts a string to an integer.
 * The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, 
 * takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.
 * The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.
 * If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains 
 * only whitespace characters, no conversion is performed.
 * If no valid conversion could be performed, a zero value is returned.
 * Note:
 * Only the space character ' ' is considered as whitespace character.
 * Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. If the numerical value is out of 
 * the range of representable values, INT_MAX (231 − 1) or INT_MIN (−231) is returned.
 */

//一定要把所有情况考虑清楚T T
class Solution {
public:
    int myAtoi(string str) {
        int f = 1;
        long long res = 0;
        int index = 0;
        
        while(str[index] == ' ') index++;
        //printf("%c\n", str[index]);
        if(str[index] == '-') {
            f = -1;
            index++;
        }else if(str[index] == '+') {
            index++;
        }else if(str[index] > '9' || str[index] < '0') return res;
        
        str = str.substr(index, str.length() - index + 1);
        
        for(int i = 0; i < str.length() && str[i] != ' ' && str[i] >= '0' && str[i] <= '9'; i++){
            res = res * 10 + str[i] - '0';
            //printf("%d %d\n", str[i] - '0', res);
            if(res * f > INT_MAX) return INT_MAX;
            if(res * f < INT_MIN) return INT_MIN;
        }
        
        return res * f;
    }
};