/**60 Permutation Sequence
 * The set [1,2,3,...,n] contains a total of n! unique permutations.
 * By listing and labeling all of the permutations in order, we get the following sequence for n = 3:
 *   "123"
 *   "132"
 *   "213"
 *   "231"
 *   "312"
 *   "321"
 * Given n and k, return the kth permutation sequence.
 * Note: Given n will be between 1 and 9 inclusive.
 *       Given k will be between 1 and n! inclusive.
 * example:
 * Input: n = 3, k = 3
 * Output: "213"
 */


// 找规律
class Solution {
public:
    int Jc(int n){
        int r = 1;
        for(int i = n; i >= 1; i--)
            r *= i;
        return r;
    }
    
    string getPermutation(int n, int k) {
        int res = 0;
        vector<int> flag = {1,2,3,4,5,6,7,8,9}; 
        for(int i = 1; i <= n; i++){
            int t = Jc(n - i);
            int tmp = k / t;
            if(k % t == 0)
                tmp --;
            res = res * 10 + flag[tmp];
            flag.erase(flag.begin() + tmp);
            k = k - tmp * t;
        }
        return to_string(res);
    }
};