class Solution {
  private:
    int fun(int ind, int prev_ind, vector<int>& arr, vector<vector<int>>& dp){
        if(ind < 0) return 0;
        
        if(dp[ind][prev_ind+1] != -1) return dp[ind][prev_ind+1];
        
        int take = 0;
        if(prev_ind == -1 || arr[prev_ind] > arr[ind]){
            take = 1 + fun(ind-1, ind, arr, dp);
        }
        
        int notTake = fun(ind-1, prev_ind, arr, dp);
        
        return dp[ind][prev_ind+1] = max(take, notTake);
    }
    
  public:
    int lis(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return fun(n-1, -1, arr, dp);
    }
};