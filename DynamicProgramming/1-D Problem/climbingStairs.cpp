class Solution {
private:
    int fun(int n, vector<int>& dp){
        if(n < 0) return 0;
        if(dp[n] != INT_MAX) return dp[n];

        return dp[n] = fun(n-1, dp) + fun(n-2, dp);
    }

public:
    // int climbStairs(int n) {
    //     vector<int> dp(n+1, INT_MAX);
    //     dp[0] = 1;

    //     return fun(n, dp);
    // }

    int climbStairs(int n) {
        int prev1 = 0, prev2 = 1;

        for(int i = 1; i <= n; i++){
            int temp = prev2;
            prev2 = prev1 + prev2;
            prev1 = temp;
        }

        return prev2;
};