class Solution {
  private:
    int fun(int row1, int col1, int col2, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp){
        if(col1 < 0 || col1 >= grid[0].size() || col2 < 0 || col2 >= grid[0].size()) return INT_MIN;
        
        if(row1 == grid.size()-1){
            if(col1 == col2) return grid[row1][col1];
            return grid[row1][col1] + grid[row1][col2];
        } 
        
        if(dp[row1][col1][col2] != -1) return dp[row1][col1][col2];
        
        int maxSum = 0;
        for(int i = -1; i <= 1; i++){
            for(int j = -1; j <= 1; j++){
                int sum = 0;
                if(col1 == col2){
                    sum = grid[row1][col1] + fun(row1+1, col1+i, col2+j, grid, dp);
                }
                else{
                    sum = grid[row1][col1] + grid[row1][col2] + fun(row1+1, col1+i, col2+j, grid, dp);
                }
                
                maxSum = max(maxSum, sum);
            }
        }
        
        return dp[row1][col1][col2] = maxSum;
    }
    
  public:
    // int maxChocolate(vector<vector<int>>& grid) {
    //     // code here
    //     int n = grid.size();
    //     int m = grid[0].size();
        
    //     vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
    //     return fun(0, 0, m-1, grid, dp);
    // }

    int maxChocolate(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> prev0(m, vector<int>(m, -1));
        
        for(int col1 = 0; col1 < m; col1++){
            for(int col2 = 0; col2 < m; col2++){
                if(col1 == col2){
                    prev0[col1][col2] = grid[n-1][col1];
                }
                else{
                    prev0[col1][col2] = grid[n-1][col1] + grid[n-1][col2];
                }
            }
        }
        
        for(int row = n-2; row >= 0; row--){
            vector<vector<int>> prev1(m, vector<int>(m));
            for(int col1 = 0; col1 < m; col1++){
                for(int col2 = 0; col2 < m; col2++){
                    
                    int maxSum = INT_MIN;
                    for(int i = -1; i <= 1; i++){
                        for(int j = -1; j <= 1; j++){
                            int sum = 0;
                            if(col1+i >= 0 && col1+i < m && col2+j >= 0 && col2+j < m){
                                if(col1 == col2){
                                    sum = grid[row][col1] + prev0[col1+i][col2+j];
                                }
                                else{
                                    sum = grid[row][col1] + grid[row][col2] + prev0[col1+i][col2+j];
                                }
                            }
                            
                            maxSum = max(maxSum, sum);
                        }
                    }
                    prev1[col1][col2] = maxSum;
                }
            }
            prev0 = prev1;
        }
        
        return prev0[0][m-1];
    }
};