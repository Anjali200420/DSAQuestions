class Solution {
private:
    long long fun(int rowInd, int colInd, int neutral, vector<vector<int>>& coins, vector<vector<vector<int>>>& dp){
        if(colInd < 0 || rowInd < 0) return INT_MIN;

        if(rowInd == 0 && colInd == 0){
            if(coins[rowInd][colInd] < 0 && neutral > 0) return 0;
            else return coins[0][0];
        };

        if(dp[rowInd][colInd][neutral] != INT_MAX) return dp[rowInd][colInd][neutral];

        long long ans = INT_MIN;

        // When you find Robber
        if(coins[rowInd][colInd] < 0){
            long long upNeutralized = INT_MIN;
            if(neutral > 0) upNeutralized = fun(rowInd-1, colInd, neutral-1, coins, dp);

            long long upNotNeutralized = fun(rowInd-1, colInd, neutral, coins, dp) + coins[rowInd][colInd];

            long long leftNeutralized = INT_MIN;
            if(neutral > 0) leftNeutralized = fun(rowInd, colInd-1, neutral-1, coins, dp);
            
            long long leftNotNeutralized = fun(rowInd, colInd-1, neutral, coins, dp) + coins[rowInd][colInd];

            ans = max(max(upNeutralized, upNotNeutralized), max(leftNeutralized, leftNotNeutralized));
        }
        // When you find coin
        else{
            long long up = fun(rowInd-1, colInd, neutral, coins, dp) + coins[rowInd][colInd];
            long long left = fun(rowInd, colInd-1, neutral, coins, dp) + coins[rowInd][colInd];

            ans = max(up, left);
        }

        return dp[rowInd][colInd][neutral] = ans;
    }

public:
    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size();
        int m = coins[0].size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(3, INT_MAX)));

        return fun(n-1, m-1, 2, coins, dp);
    }
};