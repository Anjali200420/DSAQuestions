class Solution {
private:
    bool isValid(int row, int col, vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();

        if((row >= 0 && row < n) && (col >= 0 && col < m)) return true;
        return false;
    }

public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if(grid[0][0] == 1 || grid[n-1][m-1] == 1) return -1;

        queue<pair<int, int>> q;
        vector<vector<int>> dist(n, vector<int>(m, -1));

        q.push({0, 0});
        dist[0][0] = 1;
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;

            int dis = dist[row][col];

            q.pop();

            for(int i = -1; i <= 1; i++){
                for(int j = -1; j <= 1; j++){
                    int newRow = row + i;
                    int newCol = col + j;

                    if(isValid(newRow, newCol, grid) && grid[newRow][newCol] == 0){
                        if(dist[newRow][newCol] == -1 || dis + 1 < dist[newRow][newCol]){
                            dist[newRow][newCol] = 1 + dis;
                            q.push({newRow, newCol});
                        }
                    }
                }
            }
        }
        return dist[n-1][m-1];
    }
};