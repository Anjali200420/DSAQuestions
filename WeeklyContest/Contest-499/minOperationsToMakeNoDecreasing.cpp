class Solution {
public:
    long long minOperations(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;

        for(int ind = 1; ind < n; ind++){
            if(nums[ind] < nums[ind-1]){
                long long x = (long long)nums[ind-1] - nums[ind];
                ans += x;
            }
        }

        return ans;
    }
};