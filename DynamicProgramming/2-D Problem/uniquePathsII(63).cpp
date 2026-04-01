class Solution {
private:
    int fun(int rowInd, int colInd, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp){
        if(rowInd < 0 || colInd < 0) return 0;
        if(obstacleGrid[rowInd][colInd] == 1) return 0;

        if(rowInd == 0 && colInd == 0) return 1;

        if(dp[rowInd][colInd] != -1) return dp[rowInd][colInd];

        int up = fun(rowInd - 1, colInd, obstacleGrid, dp);
        int left = fun(rowInd, colInd - 1, obstacleGrid, dp);

        return dp[rowInd][colInd] = (up + left);
    }

public:
    // int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    //     int n = obstacleGrid.size();
    //     int m = obstacleGrid[0].size();

    //     vector<vector<int>> dp(n, vector<int>(m, -1));
    //     return fun(n-1, m-1, obstacleGrid, dp);
    // }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        if(obstacleGrid[0][0] == 1) return 0;

        vector<int> prev0(m, 0);
        for(int col = 0; col < m; col++){
            if(obstacleGrid[0][col] == 1) break;
            prev0[col] = 1;
        }
        
        for(int i = 1; i < n; i++){
            vector<int> prev1(m);
            for(int j = 0; j < m; j++){
                if(i == 0 && j == 0) continue;
                if(obstacleGrid[i][j] == 1) continue;

                int up = 0;
                if(i > 0) up = prev0[j];

                int left = 0;
                if(j > 0) left = prev1[j-1];

                prev1[j] = up + left;
            }
            prev0 = prev1;
        }

        return prev0[m-1];
    }
};