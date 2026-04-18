int fun(int ind, int wt, vector<int>& profit, vector<int>& weight, vector<vector<int>>& dp){
    if(ind == 0){
        if(weight[ind] <= wt) return profit[ind]*(wt/weight[ind]);
        return 0;
    }

    if(dp[ind][wt] != -1) return dp[ind][wt];

    int notTake = fun(ind-1, wt, profit, weight, dp);
    
    int take = 0;
    if(weight[ind] <= wt){
        take = profit[ind] + fun(ind, wt-weight[ind], profit, weight, dp);
    }

    return dp[ind][wt] = max(take, notTake);
}

// int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
//     // Write Your Code Here.
//     vector<vector<int>> dp(n, vector<int>(w+1, -1));

//     return fun(n-1, w, profit, weight, dp);
// }

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    // Write Your Code Here.
    vector<int> cur(w+1, 0);

    for(int i = weight[0]; i <= w; i++){
        cur[i] = profit[0]*(i/weight[0]);
    }

    for(int ind = 1; ind < n; ind++){
        for(int wt = 0; wt <= w; wt++){
            int notTake = cur[wt];

            int take = 0;
            if(weight[ind] <= wt){
                take = profit[ind] + cur[wt-weight[ind]];
            }

            cur[wt] = max(take, notTake);
        }
    }

    return cur[w];
}