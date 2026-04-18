class Solution {
private:
    int fun(int ind, int canBuy, vector<int>& prices, vector<vector<int>>& dp){
        if(ind >= prices.size()) return 0;

        if(dp[ind][canBuy] != -1) return dp[ind][canBuy];

        if(canBuy){
            return dp[ind][canBuy] = max(-prices[ind] + fun(ind+1, 0, prices, dp), fun(ind+1, 1, prices, dp));
        }

        return dp[ind][canBuy] = max(prices[ind] + fun(ind+2, 1, prices, dp), fun(ind+1, 0, prices, dp));
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
        vector<int> prev1(2, 0);
        
        for(int ind1 = n-1; ind1 >= 0; ind1--){
            vector<int> prev2(2, 0);
            for(int ind2 = 0; ind2 <= 1; ind2++){
                if(ind2){
                    prev2[ind2] = max(-prices[ind1] + prev1[0], prev1[1]);
                }
                else{
                    prev2[ind2] = max(prices[ind1] + prev0[1], prev1[0]);
                }
            }
            prev0 = prev1;
            prev1 = prev2;
        }

        return prev1[1];
    }
};