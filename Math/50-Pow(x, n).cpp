/**50 Pow(x, n)
 * Implement pow(x, n), which calculates x raised to the power n (xn).
 * Example 1:
 * Input: 2.00000, 10
 * Output: 1024.00000
 */
 
// 需要考虑的几点：
// 1. n为负值，需要取绝对值
// 2. n为INT_MIN的时候，取绝对值会导致溢出
// 3. 超时


// 参考大神的迭代解法Σ(っ °Д °;)っ

class Solution {
public:
    double myPow(double x, int n) {
        double res = 1.00000 ;
        for(int i = n ; i != 0 ; i /=2 )
        {
            if(i%2 != 0 )  res *= x ;
            x *=x ; 
        }      
        return n< 0 ? 1/res :res ;
    }
};