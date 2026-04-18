class Solution {
  private:
    int fun(int ind, int target, vector<int>& arr, vector<vector<int>>& dp){
        if(ind == 0){
            if(target == 0 && arr[ind] == 0) return 2;
            else if(target == 0 || arr[ind] == target) return 1;
            return 0;
        }
        
        if(dp[ind][target] != -1) return dp[ind][target];
        
        int notPick = fun(ind-1, target, arr, dp);
        int pick = 0;
        if(arr[ind] <= target){
            pick = fun(ind-1, target-arr[ind], arr, dp);
        }
        
        return dp[ind][target] = (pick + notPick);
    }
    
  public:
    // int countPartitions(vector<int>& arr, int diff) {
    //     // Code here
    //     int n = arr.size();
        
    //     int totalSum = accumulate(arr.begin(), arr.end(), 0);
    //     int targetSum = (totalSum - diff) / 2;
        
    //     if(targetSum < 0 || (totalSum - diff)%2 != 0) return 0;
        
    //     vector<vector<int>> dp(n, vector<int>(targetSum+1, -1));
    //     return fun(n-1, targetSum, arr, dp);
    // }

    int countPartitions(vector<int>& arr, int diff) {
        // Code here
        int n = arr.size();
        
        int totalSum = accumulate(arr.begin(), arr.end(), 0);
        int targetSum = (totalSum - diff) / 2;
        
        if(targetSum < 0 || (totalSum - diff)%2 != 0) return 0;
        
        vector<int> prev0(targetSum+1, 0);
        
        if(arr[0] == 0) prev0[0] = 2;
        else prev0[0] = 1;
        
        if(arr[0] <= targetSum && arr[0] != 0){
            prev0[arr[0]] += 1;
        }
        
        for(int ind = 1; ind < n; ind++){
            vector<int> prev1(targetSum+1, 0);
            if(arr[0] == 0) prev1[0] = 2;
            else prev1[0] = 1;
            
            for(int target = 0; target <= targetSum; target++){
                int notPick = prev0[target];
                
                int pick = 0;
                if(arr[ind] <= target) pick = prev0[target-arr[ind]];
                
                prev1[target] = (pick + notPick);
            }
            prev0 = prev1;
        }
        
        return prev0[targetSum];
    }
};