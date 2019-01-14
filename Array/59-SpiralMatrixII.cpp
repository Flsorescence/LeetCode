/* 59 Spiral Matrix II
 * Given a positive integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
 * example:
 * Input: 3
 * Output:
 * [
 *  [ 1, 2, 3 ],
 *  [ 8, 9, 4 ],
 *  [ 7, 6, 5 ]
 * ]
 */

//同Spiral Matrix
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int x1 = 0, y1 = 0, x2 = n-1, y2 = n-1;
        int count = 0;
        while(count < n * n){
            for(int j = y1; j <= y2; j++){
                count++;
                res[x1][j] = count;
            }
            for(int i = x1 + 1; i <= x2; i++){
                count++;
                res[i][y2] = count;
            }
            if(count == n * n) break;
            for(int j = y2 - 1; j >= y1; j--){
                count++;
                res[x2][j] = count;
            }
            for(int i = x2 - 1; i >= x1 + 1; i--){
                count++;
                res[i][y1] = count;
            }
            x1++; x2--;
            y1++; y2--;
        }
        return res;
    }
};