class Solution {
private:
    bool fun(int ind, int target, vector<int>& nums, vector<vector<int>>& dp){
        if(target == 0) return true;
        if(ind == 0) return (nums[ind] == target);

        if(dp[ind][target] != -1) return dp[ind][target];

        bool notPick = fun(ind-1, target, nums, dp);

        bool pick = false;
        if(nums[ind] <= target){
            pick = fun(ind-1, target-nums[ind], nums, dp);
        }

        return dp[ind][target] = pick || notPick;
    }

public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int totalSum = 0;
        for(int ind = 0; ind < n; ind++){
            totalSum += nums[ind];
        }

        if(totalSum%2 != 0) return false;

        int target = totalSum/2;
        vector<vector<int>> dp(n, vector<int>(target+1, -1));

        return fun(n-1, target, nums, dp);
    }
};