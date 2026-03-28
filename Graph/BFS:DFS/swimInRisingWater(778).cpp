class Solution {
private:
    bool isValid(int row, int col, int n, int m){
        if((row >= 0 && row < n) && (col >= 0 && col < m)) return true;
        return false;
    }

    bool isPossible(vector<vector<int>>& grid, vector<vector<int>>& vis, int t, int n, int m){
        if(grid[0][0] > t) return false;

        queue<pair<int, int>> q;
        q.push({0, 0});
        vis[0][0] = 1;

        int delRow[4] = {-1, 0, 1, 0};
        int delCol[4] = {0, 1, 0, -1};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;

            q.pop();

            if(row == n-1 && col == m-1) return true;

            for(int i = 0; i < 4; i++){
                int newRow = row + delRow[i];
                int newCol = col + delCol[i];

                if(isValid(newRow, newCol, n, m) && grid[newRow][newCol] <= t && !vis[newRow][newCol]){
                    q.push({newRow, newCol});
                    vis[newRow][newCol] = 1;
                }
            }
        }
        return false;
    }

public:
    int swimInWater(vector<vector<int>>& grid) {
        int n =  grid.size();
        int m = grid[0].size();

        int low = 0, high = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                low = min(low, grid[i][j]);
                high = max(high, grid[i][j]);
            }
        }

        while(low <= high){
            vector<vector<int>> vis(n, vector<int>(m, 0));
            int mid = (low + high) / 2;

            if(isPossible(grid, vis, mid, n, m)) high = mid - 1;
            else low = mid + 1;
        }

        return low;
    }
};