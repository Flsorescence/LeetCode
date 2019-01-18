/* 73 Set Matrix Zeroes
 * Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.
 * example:
 * Input: 
 * [
 *   [1,1,1],
 *   [1,0,1],
 *   [1,1,1]
 * ]
 * Output: 
 * [
 *   [1,0,1],
 *   [0,0,0],
 *   [1,0,1]
 * ]
 */

 
//用两个数组分别存储有0的行数和列数，需要两次循环，时间复杂度为O(2mn)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> rows, cols;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0){
                    rows.push_back(i);
                    cols.push_back(j);
                }
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(find(rows.begin(),rows.end(),i) != rows.end() || find(cols.begin(),cols.end(),j) != cols.end())
                    matrix[i][j] = 0;
            }
        }
    }
};