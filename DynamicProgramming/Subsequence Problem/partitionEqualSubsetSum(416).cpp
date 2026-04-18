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
    // bool canPartition(vector<int>& nums) {
    //     int n = nums.size();

    //     int totalSum = 0;
    //     for(int ind = 0; ind < n; ind++){
    //         totalSum += nums[ind];
    //     }

    //     if(totalSum%2 != 0) return false;

    //     int target = totalSum/2;
    //     vector<vector<int>> dp(n, vector<int>(target+1, -1));

    //     return fun(n-1, target, nums, dp);
    // }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int totalSum = 0;
        for(int ind = 0; ind < n; ind++){
            totalSum += nums[ind];
        }

        if(totalSum%2 != 0) return false;

        int target = totalSum/2;
        vector<int> prev0(target+1, false);

        prev0[0] = true;

        if(nums[0] <= target){
            prev0[nums[0]] = true;
        }

        for(int ind = 1; ind < n; ind++){
            vector<int> prev1(target+1, false);
            prev1[0] = true;

            for(int tar = 1; tar <= target; tar++){
                bool notPick = prev0[tar];

                bool pick = false;
                if(nums[ind] <= tar){
                    pick = prev0[tar-nums[ind]];
                }
                
                prev1[tar] = pick || notPick;
            }
            prev0 = prev1;
        }

        return prev0[target];
    }
};