class Solution {
private:
    int fun(int ind, vector<int>& nums, int target, vector<int>& dp){
        if(ind == nums.size() - 1) return 0;

        if(dp[ind] != -1) return dp[ind];

        int ans = INT_MIN;
        for(int i = ind + 1; i < nums.size(); i++){
            if(abs(nums[i] - nums[ind]) <= target){
                ans = max(ans, 1 + fun(i, nums, target, dp));
            }
        }

        return dp[ind] = ans;
    }

public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();

        vector<int> dp(n, -1);
        return (fun(0, nums, target, dp) < 0 ? -1 : fun(0, nums, target, dp));
    }
};