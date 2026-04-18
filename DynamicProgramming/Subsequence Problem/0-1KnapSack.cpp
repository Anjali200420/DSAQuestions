class Solution {
  private:
    int fun(int ind, int w, vector<int>& val, vector<int>& wt, vector<vector<int>>& dp){
        if(ind == 0){
            if(wt[ind] <= w) return val[ind];
            return 0;
        }
        
        if(dp[ind][w] != -1) return dp[ind][w];
        
        int notTake = fun(ind-1, w, val, wt, dp);
        
        int take = 0;
        if(wt[ind] <= w){
            take = val[ind] + fun(ind-1, w-wt[ind], val, wt, dp);
        }
        
        return dp[ind][w] = max(take, notTake);
    }
    
  public:
    // int knapsack(int W, vector<int> &val, vector<int> &wt) {
    //     // code here
    //     int n = val.size();
        
    //     vector<vector<int>> dp(n, vector<int>(W+1, -1));
        
    //     return fun(n-1, W, val, wt, dp);
    // }

    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = val.size();
        
        vector<int> prev0(W+1, 0);
        
        for(int ind = wt[0]; ind <= W; ind++){
            prev0[ind] = val[0];
        }
        
        for(int ind = 1; ind < n; ind++){
            vector<int> prev1(W+1, 0);
            for(int weight = 1; weight <= W; weight++){
                int notTake = prev0[weight];
                
                int take = 0;
                if(wt[ind] <= weight){
                    take = val[ind] + prev0[weight-wt[ind]];
                }
                
                prev1[weight] = max(take, notTake);
            }
            prev0 = prev1;
        }
        
        return prev0[W];
    }
};