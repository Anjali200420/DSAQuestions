class Solution {
private:
    void fun(int ind, int prev_ind, vector<int>& nums, vector<int>& temp, vector<int>& ans){
        if(ind == nums.size()){
            if(temp.size() > ans.size()) ans = temp;
            return;
        }

        if(prev_ind == -1 || (nums[ind] % nums[prev_ind]) == 0 || (nums[prev_ind] % nums[ind] == 0)){
            temp.push_back(nums[ind]);
            fun(ind+1, ind, nums, temp, ans);
            temp.pop_back();
        } 

        fun(ind+1, prev_ind, nums, temp, ans);
    }

public:
    // vector<int> largestDivisibleSubset(vector<int>& nums) {
    //     int n = nums.size();

    //     vector<int> ans;
    //     vector<int> temp;

    //     sort(nums.begin(), nums.end());
    //     fun(0, -1, nums, temp, ans);

    //     return ans;
    // }

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1);
        vector<int> hash(n);

        for(int ind = 0; ind < n; ind++) hash[ind] = ind;

        int maxi = 1, maxInd = 0;
        for(int ind1 = 1; ind1 < n; ind1++){
            for(int ind2 = 0; ind2 < ind1; ind2++){
                if((nums[ind2] % nums[ind1] == 0) || (nums[ind1] % nums[ind2] == 0)){
                    if(dp[ind1] < 1 + dp[ind2]){
                        dp[ind1] = 1 + dp[ind2];
                        hash[ind1] = ind2;
                    }
                }
            }

            if(maxi < dp[ind1]){
                maxi = dp[ind1];
                maxInd = ind1;
            }
        }

        vector<int> ans;
        while(hash[maxInd] != maxInd){
            ans.push_back(nums[maxInd]);

            maxInd = hash[maxInd];
        }

        ans.push_back(nums[maxInd]);

        return ans;
    }
};