class Solution {
private:
    long long fun(int ind, int amount, vector<int>& coins, vector<vector<int>>& dp){
        if(ind == 0){
            if(amount%coins[ind] != 0) return INT_MAX;
            return amount/coins[ind];
        }

        if(dp[ind][amount] != -1) return dp[ind][amount];

        long long notTake = fun(ind-1, amount, coins, dp);
        
        long long take = INT_MAX;
        if(coins[ind] <= amount){
            take = 1 + fun(ind, amount - coins[ind], coins, dp);
        }

        return dp[ind][amount] = min(take, notTake);
    }

public:
    // int coinChange(vector<int>& coins, int amount) {
    //     int n = coins.size();

    //     vector<vector<int>> dp(n, vector<int>(amount+1, -1));

    //     return fun(n-1, amount, coins, dp) == INT_MAX ? -1 : fun(n-1, amount, coins, dp);
    // }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<int> cur(vector<int>(amount+1, INT_MAX));

        cur[0] = 0;

        for(int col = coins[0]; col <= amount; col++){
            if(col%coins[0] != 0) continue;

            cur[col] = col/coins[0];
        }

        for(int ind = 1; ind < n; ind++){
            for(int amt = 1; amt <= amount; amt++){
                long long notTake = cur[amt];

                long long take = INT_MAX;
                if(coins[ind] <= amt){
                    take = 1 + 1LL*cur[amt-coins[ind]];
                }

                cur[amt] = min(take, notTake);
            }
        }

        return cur[amount] == INT_MAX ? -1 : cur[amount];
    }
};