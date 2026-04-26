class Solution {
private:
    bool isValid(int row, int col, vector<vector<char>>& grid){
        int n = grid.size();
        int m = grid[0].size();

        if((row >= 0 && row < n) && (col >= 0 && col < m)) return true;
        return false;
    }

    bool dfs(int row, int col, int pRow, int pCol, char ch, vector<vector<int>>& vis, vector<vector<char>>& grid){
        vis[row][col] = 1;

        int delRow[4] = {-1, 0, 1, 0};
        int delCol[4] = {0, 1, 0, -1};

        for(int i = 0; i < 4; i++){
            int newRow = row + delRow[i];
            int newCol = col + delCol[i];

            if(isValid(newRow, newCol, grid) && grid[newRow][newCol] == ch){
                if(!vis[newRow][newCol]){
                    if(dfs(newRow, newCol, row, col, ch, vis, grid)) return true;
                }
                else if(newRow != pRow || newCol != pCol) return true;
            } 
        }

        return false;
    }

public:
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                char ch = grid[i][j];
                if(!vis[i][j]){
                    if(dfs(i, j, i, j, ch, vis, grid)) return true;
                }
            }
        }

        return false;
    }
};