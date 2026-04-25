class Solution {
  private:
    int fun(int ind, int prev_ind, vector<int>& arr, vector<vector<int>>& dp){
        if(ind < 0) return 0;
        
        if(dp[ind][prev_ind+1] != -1) return dp[ind][prev_ind+1];
        
        int take = 0;
        if(prev_ind == -1 || arr[prev_ind] > arr[ind]){
            take = 1 + fun(ind-1, ind, arr, dp);
        }
        
        int notTake = fun(ind-1, prev_ind, arr, dp);
        
        return dp[ind][prev_ind+1] = max(take, notTake);
    }
    
  public:
    // int lis(vector<int>& arr) {
    //     // code here
    //     int n = arr.size();
        
    //     vector<vector<int>> dp(n, vector<int>(n+1, -1));
    //     return fun(n-1, -1, arr, dp);
    // }

    // int lis(vector<int>& arr) {
    //     // code here
    //     int n = arr.size();
        
    //     vector<int> prev0(n+1, 0);
        
    //     for(int ind1 = n-1; ind1 >= 0; ind1--){
    //         vector<int> prev1(n+1, 0);
    //         for(int ind2 = ind1-1; ind2 >= -1; ind2--){
    //             int take = 0;
    //             if(ind2 == -1 || arr[ind1] > arr[ind2]){
    //                 take = 1 + prev0[ind1+1];
    //             }
                
    //             int notTake = prev0[ind2+1];
                
    //             prev1[ind2+1] = max(take, notTake);
    //         }
            
    //         prev0 = prev1;
    //     }
        
    //     return prev0[0];
    // }

    // int lis(vector<int>& arr) {
    //     // code here
    //     int n = arr.size();
        
    //     vector<int> temp;
    //     temp.push_back(arr[0]);
        
    //     for(int ind = 1; ind < n; ind++){
    //         if(arr[ind] > temp.back()) temp.push_back(arr[ind]);
    //         else{
    //             int tempInd = lower_bound(temp.begin(), temp.end(), arr[ind]) - temp.begin();
                
    //             temp[tempInd] = arr[ind];
    //         }
    //     }
        
    //     return temp.size();
    // }

    int n = arr.size();
        
        vector<int> hashing(n, 1);
        
        for(int ind1 = 1; ind1 < n; ind1++){
            for(int ind2 = 0; ind2 < ind1; ind2++){
                if(arr[ind2] < arr[ind1]){
                    hashing[ind1] = max(1+hashing[ind2], hashing[ind1]);
                }
            }
        }
        
        int ans = 0;
        for(auto it : hashing){
            ans = max(ans, it);
        }
        
        return ans;
};