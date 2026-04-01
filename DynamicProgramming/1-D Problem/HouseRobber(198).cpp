class Solution {
private:
    int fun(int ind, vector<int>& nums, vector<int>& dp){
        if(ind < 0) return 0;
        
        if(dp[ind] != INT_MAX) return dp[ind];

        int notPick = fun(ind-1, nums, dp);
        int pick = nums[ind] + fun(ind-2, nums, dp);

        return dp[ind] = max(pick, notPick);
    }

public:
    // int rob(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int> dp(n, INT_MAX);

    //     dp[0] == nums[0];
    //     return fun(n-1, nums, dp);
    // }

    int rob(vector<int>& nums) {
        int n = nums.size();

        int prev1 = 0, prev2 = nums[0];
        for(int i = 1; i < n; i++){
            int pick = nums[i] + prev1;
            int notPick = prev2;

            prev1 = prev2;
            prev2 = max(pick, notPick);
        }

        return prev2;
    }
};