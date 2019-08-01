/**221 Maximal Square
 * Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.
 * Example:
 * Input: 
 * 1 0 1 0 0
 * 1 0 1 1 1
 * 1 1 1 1 1
 * 1 0 0 1 0
 * Output: 4
 */
 
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int h = matrix.size();
        if(h == 0) return 0;
        int w = matrix[0].size();
        int flag[h][w] = {0};
        int max_len = 0;
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(i == 0 || j == 0){
                    flag[i][j] = matrix[i][j] - '0';
                }else{
                    if(matrix[i][j] == '1') flag[i][j] = min(flag[i-1][j-1], min(flag[i-1][j], flag[i][j-1])) + 1;
                }
                max_len = max(max_len, flag[i][j]);
            }
        }
        return max_len * max_len;
    }
};