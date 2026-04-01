class Solution {
  private:
    int fun(int rowInd, int colInd, vector<vector<int>>& mat, vector<vector<int>>& dp){
        if(colInd < 0 || colInd >= mat[0].size()) return INT_MIN;
        
        if(rowInd == 0) return mat[rowInd][colInd];
        
        if(dp[rowInd][colInd] != -1) return dp[rowInd][colInd];
        
        int diagonalLeft = mat[rowInd][colInd] + fun(rowInd-1, colInd-1, mat, dp);
        int up = mat[rowInd][colInd] + fun(rowInd-1, colInd, mat, dp);
        int diagonalRight = mat[rowInd][colInd] + fun(rowInd-1, colInd+1, mat, dp);
        
        return dp[rowInd][colInd] = max(up, max(diagonalLeft, diagonalRight));
    }
    
  public:
    // int maximumPath(vector<vector<int>>& mat) {
    //     // code here
    //     int n = mat.size();
    //     int m = mat[0].size();
        
    //     int ans = 0;
    //     vector<vector<int>> dp(n, vector<int>(m, -1));
    //     for(int col = 0; col < m; col++){
    //         ans = max(ans, fun(n-1, col, mat, dp));
    //     }
        
    //     return ans;
    // }

    int maximumPath(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        
        vector<int> prev0(m);
        
        for(int col = 0; col < m; col++){
            prev0[col] = mat[0][col];
        }
        
        for(int row = 1; row < n; row++){
            vector<int> prev1(m);
            for(int col = 0; col < m; col++){
                int up = prev0[col];
                
                int diagLeft = INT_MIN;
                if(col > 0) diagLeft = prev0[col-1];
                
                int diagRight = INT_MIN;
                if(col != m-1) diagRight = prev0[col+1];
                
                prev1[col] = max(up, max(diagLeft, diagRight)) + mat[row][col];
            }
            prev0 = prev1;
        }
        
        int ans = 0;
        for(int col = 0; col < m; col++){
            ans = max(ans, prev0[col]);
        }
        
        return ans;
    }
};