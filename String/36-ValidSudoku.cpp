/**36 Valid Sudoku
 * Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
 * Each row must contain the digits 1-9 without repetition.
 * Each column must contain the digits 1-9 without repetition.
 * Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.
 */
 
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][9] = {0}, col[9][9] = {0}, sub[9][9] = {0};
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    int num = board[i][j] - '0' - 1;
                    int index = i /3 * 3 + j / 3;
                    if(row[i][num] || col[j][num] || sub[index][num])
                        return false;
                    row[i][num] = col[j][num] = sub[index][num] = 1;
                }
            }
        }
        return true;
    }
};