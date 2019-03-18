/**29 Divide Two Integers 
 * Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.
 * Return the quotient after dividing dividend by divisor.
 * The integer division should truncate toward zero.
 * example:
 * Input: dividend = 10, divisor = 3
 * Output: 3
 */
 
class Solution {
public:
    int divide(int dividend, int divisor) {
        long long m = abs((long long)dividend), n = abs((long long) divisor);
        if(m < n) return 0;
        long long res = 0;
        while(m >= n){
            long long t = n, p = 1;
            while(m > (t << 1)){
                t <<= 1;
                p <<= 1;
            }
            res += p;
            m -= t;
        }
        if((dividend < 0) ^ (divisor < 0)) res = -res;
        return res < INT_MAX? res: INT_MAX;
    }
};