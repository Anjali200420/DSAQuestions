class Solution {
private:
    int fun(int ind, vector<int>& nums, vector<int>& dp){
        if(ind < 0) return 0;

        if(dp[ind] != INT_MAX) return dp[ind];

        int pick = nums[ind] + fun(ind-2, nums, dp);
        int notPick = fun(ind-1, nums, dp);

        return dp[ind] = max(pick, notPick);
    }

    // int fun(int ind, vector<int>& nums){
    //     int n = nums.size();
    //     int prev1 = 0, prev2 = nums[0];

    //     for(int i = 1; i < n; i++){
    //         int pick = nums[i] + prev1;
    //         int notPick = prev2;

    //         prev1 = prev2;
    //         prev2 = max(pick, notPick);
    //     }

    //     return prev2;
    // }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];

        vector<int> temp1;
        vector<int> temp2;

        for(int i = 0; i < n; i++){
            if(i != 0) temp1.push_back(nums[i]);
            if(i != n-1) temp2.push_back(nums[i]);
        }

        vector<int> dp1(n-1, INT_MAX);
        vector<int> dp2(n-1, INT_MAX);

        dp1[0] = nums[1];
        dp2[0] = nums[0];
        return max(fun(n-2, temp1, dp1), fun(n-2, temp2, dp2));
    }
};