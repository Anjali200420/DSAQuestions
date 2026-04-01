class Solution {
private:
    int fun(int rowInd, int colInd, vector<vector<int>>& dp){
        if(rowInd == 0 && colInd == 0) return 1;
        if(rowInd < 0 || colInd < 0) return 0;

        if(dp[rowInd][colInd] != -1) return dp[rowInd][colInd];

        int up = fun(rowInd - 1, colInd, dp);
        int left = fun(rowInd, colInd - 1, dp);

        return dp[rowInd][colInd] = (up + left);
    }
public:
    // int uniquePaths(int m, int n) {
    //     vector<vector<int>> dp(m, vector<int>(n, -1));
    //     return fun(m-1, n-1, dp);
    // }

    int uniquePaths(int m, int n) {
        vector<int> prev0(n, 1);

        for(int row = 1; row < m; row++){
            vector<int> prev1(n);
            for(int col = 0; col < n; col++){
                if(row == 0 && col == 0) continue;

                int up = 0;
                if(row > 0){
                    up = prev0[col];
                }

                int left = 0;
                if(col > 0){
                    left = prev1[col-1];
                }

                prev1[col] = up + left;
            }
            prev0 = prev1;
        }

        return prev0[n-1];
    }
};