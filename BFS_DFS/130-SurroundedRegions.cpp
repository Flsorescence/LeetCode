/**130 Surrounded Regions
 * Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.
 * A region is captured by flipping all 'O's into 'X's in that surrounded region.
 * Example:
 *   X X X X
 *   X O O X
 *   X X O X
 *   X O X X
 * After running your function, the board should be:
 *   X X X X
 *   X X X X
 *   X X X X
 *   X O X X
 * Explanation:
 * Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. 
 * Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. 
 * Two cells are connected if they are adjacent cells connected horizontally or vertically.
 */
 
// 先从边界上的O出发，通过BFS/DFS将边界上及其和边界相连的O先标记为*，然后遍历二维矩阵，将矩阵中的O变为X，*变为O
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        if(row == 0) return;
        int col = board[0].size();
        if(col == 0) return;
        
        for(int j = 0; j < col; j++){
            DFS(board, 0, j);
            DFS(board, row-1, j);
        }
        
        for(int i = 0; i < row; i++){
            DFS(board, i, 0);
            DFS(board, i, col-1);
        }
        
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
                if(board[i][j] == '*') board[i][j] = 'O';
            }
        }
    }
    
    void DFS(vector<vector<char>>& board, int i, int j){
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != 'O') return;
        board[i][j] = '*';
        DFS(board, i-1, j);
        DFS(board, i+1, j);
        DFS(board, i, j-1);
        DFS(board, i, j+1);
    }
};