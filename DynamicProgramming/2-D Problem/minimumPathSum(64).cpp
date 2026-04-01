class Solution {
private:
    long long fun(int rowInd, int colInd, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(rowInd < 0 || colInd < 0) return INT_MAX;
        if(rowInd == 0 && colInd == 0) return grid[0][0];

        if(dp[rowInd][colInd] != -1) return dp[rowInd][colInd];

        long long up = fun(rowInd-1, colInd, grid, dp) + grid[rowInd][colInd];
        long long left = fun(rowInd, colInd-1, grid, dp) + grid[rowInd][colInd];

        return dp[rowInd][colInd] = min(up, left);
    }

public:
    // int minPathSum(vector<vector<int>>& grid) {
    //     int n = grid.size();
    //     int m = grid[0].size();

    //     vector<vector<int>> dp(n, vector<int>(m, -1));
    //     return fun(n-1, m-1, grid, dp);
    // }

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int> prev0(m);

        for(int col = 0; col < m; col++){
            prev0[col] = grid[0][col];

            if(col > 0) prev0[col] +=  prev0[col-1];
        }

        for(int row = 1; row < n; row++){
            vector<int> prev1(m);
            for(int col = 0; col < m; col++){
                long long up = prev0[col] + grid[row][col];

                long long left = INT_MAX;
                if(col > 0) left = prev1[col-1] + grid[row][col];

                prev1[col] = min(up, left);
            }

            prev0 = prev1;
        }

        return prev0[m-1];
    }
};