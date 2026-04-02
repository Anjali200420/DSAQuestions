class Solution {
  private:
    bool fun(int ind, int sum, vector<int>& arr, vector<vector<int>>& dp){
        if(sum == 0) return true;
        if(ind == 0) return (arr[ind] == sum);
        
        if(dp[ind][sum] != -1) return dp[ind][sum];
        
        bool pick = false;
        if(arr[ind] <= sum) pick = fun(ind-1, sum-arr[ind], arr, dp);
        
        bool notPick = fun(ind-1, sum, arr, dp);
        
        return dp[ind][sum] = pick || notPick;
    }
    
  public:
    // bool isSubsetSum(vector<int>& arr, int sum) {
    //     // code here
    //     int n = arr.size();
        
    //     vector<vector<int>> dp(n, vector<int>(sum+1, -1));
    //     return fun(n-1, sum, arr, dp);
    // }

    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        
        vector<bool> prev0(sum+1, false);
        prev0[0] = true;
        
        if(arr[0] <= sum){
            prev0[arr[0]] = true;
        }
        
        for(int ind = 1; ind < n; ind++){
            vector<bool> prev1(sum+1);
            prev1[0] = true;
            for(int target = 1; target <= sum; target++){
                bool notPick = prev0[target];
                bool pick = false;
                
                if(arr[ind] <= target){
                    pick = prev0[target - arr[ind]];
                }
                
                prev1[target] = pick || notPick;
            }
            prev0 = prev1;
        }
        
        return prev0[sum];
    }
};