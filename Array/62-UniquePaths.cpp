/* 62 Unique Paths
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
 * The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
 * How many possible unique paths are there?
 * Note: m and n will be at most 100.
 * Input: m = 3, n = 2
 * Output: 3
 * Explanation:
 * From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
 * 1. Right -> Right -> Down
 * 2. Right -> Down -> Right
 * 3. Down -> Right -> Right
 */

 
//每一格的路径数都是它上面和左边格子路径数之和，维护一个二维数据来保存每一格的路径数，返回右下角格子的路径数
class Solution {
public:
    int uniquePaths(int m, int n) {
        int tmp[m][n] = {0};
        tmp[0][0] = 1;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i >= 1 &&  j >= 1) tmp[i][j] = tmp[i-1][j] + tmp[i][j-1];
                else if(i == 0 && j != 0) tmp[i][j] = tmp[i][j-1];
                else if(j == 0 && i != 0) tmp[i][j] = tmp[i-1][j];
            }
        }
        return tmp[m-1][n-1];
    }
};