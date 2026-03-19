class Solution {    
private:
    bool isValid(int row, int col, vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();

        if((row >= 0 && row < n) && (col >= 0 && col < m)) return true;
        return false;
    }

public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    q.push({{i, j},0});
                    vis[i][j] = 1;
                } 
            }
        }

        int ans = 0;
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;

            int t = q.front().second;
            q.pop();

            ans = max(t, ans);

            int delRow[4] = {-1, 0, 1, 0};
            int delCol[4] = {0, 1, 0, -1};

            for(int i = 0; i < 4; i++){
                int newRow = row + delRow[i];
                int newCol = col + delCol[i];

                if(isValid(newRow, newCol, grid) && grid[newRow][newCol] == 1 && !vis[newRow][newCol]){
                    vis[newRow][newCol] = 1;
                    q.push({{newRow, newCol}, t+1});
                }
            }
            
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1 && !vis[i][j]) return -1;
            }
        }
        
        return ans;
    }
};