class Solution {
private:
    int fun(int ind, int canBuy, int noOfTransactions, vector<int>& prices, vector<vector<vector<int>>> &dp){
        if(noOfTransactions == 0 || ind == prices.size()) return 0;

        if(dp[ind][canBuy][noOfTransactions] != -1) return dp[ind][canBuy][noOfTransactions];

        if(canBuy){
            return dp[ind][canBuy][noOfTransactions] = max(-prices[ind] + fun(ind+1, 0, noOfTransactions, prices, dp), fun(ind+1, 1, noOfTransactions, prices, dp));
        }

        return dp[ind][canBuy][noOfTransactions] = max(prices[ind] + fun(ind+1, 1, noOfTransactions-1, prices, dp), fun(ind+1, 0, noOfTransactions, prices, dp));
    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> prev0(2, vector<int>(3, 0));
        
        for(int ind1 = n-1; ind1 >= 0; ind1--){
            vector<vector<int>> prev1(2, vector<int>(3, 0));
            for(int ind2 = 0; ind2 <= 1; ind2++){
                for(int cap = 1; cap <= 2; cap++){
                    if(ind2){
                        prev1[ind2][cap] = max(-prices[ind1] + prev0[0][cap], prev0[1][cap]);
                    }
                    else{
                        prev1[ind2][cap] = max(prices[ind1] + prev0[1][cap-1], prev0[0][cap]);
                    }
                }
            }
            prev0 = prev1;
        }

        return prev0[1][2];
    }
};