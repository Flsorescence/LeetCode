/**119 Pascal's Triangle II
 * Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.
 * Note that the row index starts from 0.
 * example:
 * Input: 3
 * Output: [1,3,3,1]
 */

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> matrix(1000);
        for(int i = 0; i <= rowIndex; i++){
            matrix[i].resize(i+1);
            matrix[i][0] = matrix[i][i] = 1;
            
            for(int j = 1; j < i; j++)
                matrix[i][j] = matrix[i-1][j-1] + matrix[i-1][j];
        }
        return matrix[rowIndex];
    }
};