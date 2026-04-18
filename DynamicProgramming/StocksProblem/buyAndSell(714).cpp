class Solution {
private:
    int fun(int ind, int canBuy, int fee, vector<int>& prices, vector<vector<int>> &dp){
        if(ind == prices.size()) return 0;

        if(dp[ind][canBuy] != -1) return dp[ind][canBuy];
        if(canBuy){
            return dp[ind][canBuy] = max(-prices[ind] + fun(ind+1, 0, fee, prices, dp), fun(ind+1, 1, fee, prices, dp));
        }
        else{
            return dp[ind][canBuy] = max(prices[ind] - fee + fun(ind+1, 1, fee, prices, dp), fun(ind+1, 0, fee, prices, dp));
        }
    }
    
public:
    // int maxProfit(vector<int>& prices, int fee) {
    //     int n = prices.size();

    //     vector<vector<int>> dp(n, vector<int>(2, -1));
    //     return fun(0, 1, fee, prices, dp);
    // }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();

        vector<int> prev0(2, 0);
        
        for(int ind1 = n-1; ind1 >= 0; ind1--){
            vector<int> prev1(2, 0);
            for(int ind2 = 0; ind2 <= 1; ind2++){
                if(ind2){
                    prev1[ind2] = max(-prices[ind1] + prev0[0], prev0[1]);
                }
                else{
                    prev1[ind2] = max(prices[ind1] - fee + prev0[1], prev0[0]);
                }
            }
            prev0 = prev1;
        }

        return prev0[1];
    }
};