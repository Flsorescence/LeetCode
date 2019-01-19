/* 79 Word Search
 * Given a 2D board and a word, find if the word exists in the grid.
 * The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.
 * Example:
 * board =
 * [
 *   ['A','B','C','E'],
 *   ['S','F','C','S'],
 *   ['A','D','E','E']
 * ]
 * Given word = "ABCCED", return true.
 * Given word = "SEE", return true.
 * Given word = "ABCB", return false.
 */

//广度优先遍历，对遍历过的位置进行标记，防止同一个元素遍历多次 
class Solution {
public:
    bool find(vector<vector<char>>& board, int i, int j, string word, int pos){
        if(pos == word.length()) return true;

        if(i <0 || j < 0 || i >= board.size() || j >= board[0].size()) return false;
        if(board[i][j] == word[pos]){
            board[i][j] = '*';
            if(find(board, i-1, j, word, pos+1) || 
               find(board, i+1, j, word, pos+1) || 
               find(board, i, j-1, word, pos+1) || 
               find(board, i, j+1, word, pos+1)) return true;
            board[i][j] = word[pos];
            return false;
        }
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        // if(board.size() == 0 || board[0].size() == 0) return false;
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                if(find(board, i, j, word, 0)) return true;
            }
        }
        return false;
    }
};