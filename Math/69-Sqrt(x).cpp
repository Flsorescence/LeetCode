/**69 Sqrt(x)
 * Implement int sqrt(int x).
 * Compute and return the square root of x, where x is guaranteed to be a non-negative integer.
 * Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.
 * example:
 * Input: 4
 * Output: 2
 */
 
class Solution {
public:
    int mySqrt(int x) {
        int res = 0;
        for(long long i = 1; i <= x; i++){
            long long tmp = i * i;
            if(tmp == x) return i;
            else if(tmp > x) return i - 1;
        }
        return res;
    }
};