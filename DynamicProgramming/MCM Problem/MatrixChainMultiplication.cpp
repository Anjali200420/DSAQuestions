class Solution {
  private:
    int fun(int start, int end, vector<int>& arr, vector<vector<int>>& dp){
        if(start == end) return 0;
        
        if(dp[start][end] != -1) return dp[start][end];
        
        int ans = INT_MAX;
        for(int ind = start; ind < end; ind++){
            int mult = arr[start-1]*arr[ind]*arr[end] + fun(start, ind, arr, dp) + fun(ind+1, end, arr, dp);
            ans = min(ans, mult);
        }
        
        return dp[start][end] = ans;
    }
    
  public:
    // int matrixMultiplication(vector<int> &arr) {
    //     // code here
    //     int n = arr.size();
        
    //     vector<vector<int>> dp(n, vector<int>(n, -1));
    //     return fun(1, n-1, arr, dp);
    // }

    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n = arr.size();
        
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for(int start = n-2; start >= 1; start--){
            for(int end = start + 1; end < n; end++){
                int ans = INT_MAX;
                for(int ind = start; ind < end; ind++){
                    int mult = arr[start-1]*arr[ind]*arr[end] + dp[start][ind] + dp[ind+1][end];
                    ans = min(ans, mult);
                }
                
                dp[start][end] = ans;
            }
        }
        
        return dp[1][n-1];
    }
};