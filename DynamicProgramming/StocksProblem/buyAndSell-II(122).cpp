class Solution {
private:
    int fun(int ind, int buy, vector<int>& prices, vector<vector<int>>& dp){
        if(ind == prices.size()-1){
            if(buy) return 0;
            return prices[ind];
        }

        if(dp[ind][buy] != -1) return dp[ind][buy];

        if(buy){
            return dp[ind][buy] = max(fun(ind+1, 1, prices, dp), -prices[ind] + fun(ind+1, 0, prices, dp));
        }

        return dp[ind][buy] = max(fun(ind+1, 0, prices, dp), prices[ind] + fun(ind+1, 1, prices, dp));
    }

public:
    // int maxProfit(vector<int>& prices) {
    //     int n = prices.size();

    //     vector<vector<int>> dp(n, vector<int>(2, -1));
    //     return fun(0, 1, prices, dp);
    // }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<int> prev0(2, 0);
        
        for(int ind1 = n-1; ind1 >= 0; ind1--){
            vector<int> prev1(2, 0);
            for(int ind2 = 0; ind2 <= 1; ind2++){
                if(ind2){
                    prev1[ind2] = max(-prices[ind1] + prev0[0], prev0[1]);
                }
                else{
                    prev1[ind2] = max(prices[ind1] + prev0[1], prev0[0]);
                }
            }
            prev0 = prev1;
        }

        return prev0[1];
    }
};