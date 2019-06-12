/**96 Unique Binary Search Trees
 * Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?
 */
 
class Solution {
public:
    int numTrees(int n) {
        if(n == 0 || n == 1) return 1;
        int num[n+1] = {0};
        num[0] = 1; num[1] = 1;
        for(int i = 2; i <= n; i++){
            for(int j = 0; j < i; j++){
                num[i] += num[j] * num[i-1-j];
            }
        }
        return num[n];
    }
};