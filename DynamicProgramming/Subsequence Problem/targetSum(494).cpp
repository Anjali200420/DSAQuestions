class Solution {
private:
    int fun(int ind, int target, vector<int>& nums, vector<vector<int>>& dp){
        if(ind == 0){
            if(nums[ind] == target || nums[ind] == -target){
                if(target == 0) return 2;
                return 1;
            } 
            return 0;
        }

        if(dp[ind][target] != INT_MAX) return dp[ind][target];

        int add = fun(ind-1, target - nums[ind], nums, dp);
        int sub = fun(ind-1, target + nums[ind], nums, dp);

        return dp[ind][target] = add + sub;
    }

public:
    // int findTargetSumWays(vector<int>& nums, int target) {
    //     int n = nums.size();

    //     vector<vector<int>> dp(n, vector<int>(target+1, INT_MAX));

    //     return fun(n-1, target, nums, dp);
    // }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        if((totalSum - target)%2 != 0 || totalSum < abs(target)) return 0;
        int targetSum = (totalSum - target) / 2;

        vector<int> prev0(targetSum + 1, 0);
        
        prev0[0] = 1;

        for(int col = 0; col <= targetSum; col++){
            if(nums[0] == col) prev0[col] += 1;
        }

        for(int ind = 1; ind < n; ind++){
            vector<int> prev1(targetSum+1, 0);
            prev1[0] = 1;
            for(int target = 0; target <= targetSum; target++){
                int notTake = prev0[target];

                int take = 0;
                if(nums[ind] <= target){
                    take = prev0[target-nums[ind]];
                }

                prev1[target] = take + notTake;
            }
            prev0 = prev1;
        }

        return prev0[targetSum];
    }
};