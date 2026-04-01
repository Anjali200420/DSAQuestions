class Solution {
  private:
    int fun(int rowInd, int colInd, vector<vector<int>>& mat, vector<vector<int>>& dp){
        if(rowInd == 0) return 0;
        
        if(dp[rowInd][colInd] != -1) return dp[rowInd][colInd];
        int maxSum = 0;
        for(int col = 0; col < 3; col++){
            if(col == colInd) continue;
            
            int sum = fun(rowInd-1, col, mat, dp) + mat[rowInd-1][col];
            maxSum = max(maxSum, sum);
        }
        
        return dp[rowInd][colInd] = maxSum;
    }
    
  public:
    // int maximumPoints(vector<vector<int>>& mat) {
    //     // code here
    //     int n = mat.size();
        
    //     vector<vector<int>> dp(n+1, vector<int>(4, -1));
    //     return fun(n, 3, mat, dp);
    // }

    int maximumPoints(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        
        vector<int> prev0(3);
        for(int col = 0; col < 3; col++){
            prev0[col] = mat[0][col];
        }
        
        for(int row = 1; row < n; row++){
            vector<int> prev1(3);
            for(int col = 0; col < 3; col++){
                int maxSum = 0;
                for(int task = 0; task < 3; task++){
                    if(col == task) continue;
                    int sum = prev0[task] + mat[row][col];
                    
                    maxSum = max(maxSum, sum);
                }
                
                prev1[col] = maxSum;
            }
            prev0 = prev1;
        }
        
        int ans = 0;
        for(int col = 0; col < 3; col++){
            ans = max(ans, prev0[col]);
        }
        
        return ans;
    }
};