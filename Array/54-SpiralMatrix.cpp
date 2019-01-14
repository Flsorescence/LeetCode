/* 54 Spiral Matrix
 * Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
 * Input:
 * [
 *  [ 1, 2, 3 ],
 *  [ 4, 5, 6 ],
 *  [ 7, 8, 9 ]
 * ]
 * Output: [1,2,3,6,9,8,7,4,5]
 */

 
//简单模拟，设置边界值进行循环，时间复杂度为O(n)
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.empty()) return res;
        int r = matrix.size(), c = matrix[0].size();
        int x1 = 0, y1 = 0, x2 = r-1, y2 = c-1, count = 0;
        while(count < r * c){
            for(int j = y1; j <= y2; j++){
                res.push_back(matrix[x1][j]);
                count++;
            }
            for(int i = x1 + 1; i <= x2; i++){
                res.push_back(matrix[i][y2]);
                count++;
            }
            if(count == r * c) break;
            for(int j = y2 - 1; j >= y1; j--){
                res.push_back(matrix[x2][j]);
                count++;
            }
            for(int i = x2 - 1; i > x1; i--){
                res.push_back(matrix[i][y1]);   
                count++;
            }
            x1++; x2--;
            y1++; y2--;
        }
        return res;
    }
};