/**264 Ugly Number II
 * Write a program to find the n-th ugly number.
 * Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 
 * Example:
 * Input: n = 10
 * Output: 12
 * Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
 * Note:  
 * 1 is typically treated as an ugly number.
 * n does not exceed 1690.
 */
 
class Solution {
public:
    int nthUglyNumber(int n) {
        int ugly[n];
        ugly[0] = 1;
        int x2 = 0, x3 = 0, x5 = 0;
        for(int i = 1; i < n; i++){
            ugly[i] = min(min(ugly[x2] * 2, ugly[x3] * 3), ugly[x5] * 5);
            if(ugly[x2] * 2 == ugly[i]) x2++;
            if(ugly[x3] * 3 == ugly[i]) x3++;
            if(ugly[x5] * 5 == ugly[i]) x5++;
        }
        return ugly[n-1];
    }
};