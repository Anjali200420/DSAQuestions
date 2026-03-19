class Solution {
private:
    bool isValid(int row, int col, vector<vector<char>>& grid){
        int n = grid.size();
        int m = grid[0].size();

        if((row >= 0 && row < n) && (col >= 0 && col < m)) return true;
        return false;
    }

    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& grid){
        vis[row][col] = 1;

        int delRow[4] = {-1, 0, 1, 0};
        int delCol[4] = {0, 1, 0, -1};

        for(int i = 0; i < 4; i++){
            int newRow = row + delRow[i];
            int newCol = col + delCol[i];

            if(isValid(newRow, newCol, grid) && grid[newRow][newCol] == '1' && !vis[newRow][newCol]){
                dfs(newRow, newCol, vis, grid);
            }
        }
    }

    // void bfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& grid){
    //     queue<pair<int, int>> q;

    //     q.push({row, col});
    //     vis[row][col] = 1;

    //     int delRow[4] = {-1, 0, 1, 0};
    //     int delCol[4] = {0, 1, 0, -1};

    //     while(!q.empty()){
    //         int row = q.front().first;
    //         int col = q.front().second;

    //         q.pop();

    //         for(int i = 0; i < 4; i++){
    //             int newRow = row + delRow[i];
    //             int newCol = col + delCol[i];

    //             if(isValid(newRow, newCol, grid) && grid[newRow][newCol] == '1' && !vis[newRow][newCol]){
    //                 vis[newRow][newCol] = 1;
    //                 q.push({newRow, newCol});
    //             }
    //         }
    //     }
    // }

public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    dfs(i, j, vis, grid);
                    ans++;
                } 
            }
        }

        return ans;
    }
};