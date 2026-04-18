class Solution {
private:
    int fun(int ind, int amount, vector<int>& coins, vector<vector<int>>& dp){
        if(ind == 0){
            if(amount % coins[ind] != 0) return 0;
            return 1;
        }

        if(dp[ind][amount] != -1) return dp[ind][amount];

        int notTake = fun(ind-1, amount, coins, dp);

        int take = 0;
        if(coins[ind] <= amount){
            take = fun(ind, amount - coins[ind], coins, dp);
        }

        return dp[ind][amount] = (take + notTake);
    }

public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        return fun(n-1, amount, coins, dp);
    }
};