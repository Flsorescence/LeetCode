/**200. Number of Islands
 * Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands 
 * horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
 */
 
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        int rows = grid.size();
        if(rows == 0) return res;
        int cols = grid[0].size();
        
        vector<vector<int>> visit(rows, vector<int>(cols, 0));
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == '1' && visit[i][j] == 0){
                    res++;
                    dfs(grid, visit, i, j, rows, cols);
                }
            }
        }
        return res;
    }
    
    void dfs(vector<vector<char>>& grid, vector<vector<int>>& visit, int x, int y, int rows, int cols){
        if(grid[x][y] == '1' && visit[x][y] == 0){
            visit[x][y] = 1;
            if(x-1 >= 0) dfs(grid, visit, x-1, y, rows, cols);
            if(x+1 < rows) dfs(grid, visit, x+1, y, rows, cols);
            if(y-1 >= 0) dfs(grid, visit, x, y-1, rows, cols);
            if(y+1 < cols) dfs(grid, visit, x, y+1, rows, cols);
        }
    }
};