/* 63 Unique Paths II
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
 * The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
 * An obstacle and empty space is marked as 1 and 0 respectively in the grid.
 * Now consider if some obstacles are added to the grids. How many unique paths would there be?
 * Note: m and n will be at most 100.
 * Input: 
 * [
 *   [0,0,0],
 *   [0,1,0],
 *   [0,0,0]
 * ]
 * Output: 2
 * Explanation:
 * There is one obstacle in the middle of the 3x3 grid above.
 * There are two ways to reach the bottom-right corner:
 * 1. Right -> Right -> Down -> Down
 * 2. Down -> Down -> Right -> Right
 */

 
//在62题Unique Paths的基础上，如果当前格子中有障碍物，则将当前格子的路径数设为0
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        int tmp[m][n] = {0};
        tmp[0][0] = 1;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(obstacleGrid[i][j] == 0){
                    if(i >= 1 &&  j >= 1) tmp[i][j] = tmp[i-1][j] + tmp[i][j-1];
                    else if(i == 0 && j != 0) tmp[i][j] = tmp[i][j-1];
                    else if(j == 0 && i != 0) tmp[i][j] = tmp[i-1][j];
                }else tmp[i][j] = 0;
            }
        }
        return tmp[m-1][n-1];
    }
};