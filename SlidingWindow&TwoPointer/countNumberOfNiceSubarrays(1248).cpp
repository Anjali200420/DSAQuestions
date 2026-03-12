class Solution {
private:
    int helper(vector<int>& nums, int k){
        int ans = 0;

        int l=0, r=0, cnt=0;
        while(r < nums.size()){
            cnt += nums[r]%2;

            while(cnt > k){
                cnt -= nums[l]%2;
                l++;
            }

            ans += (r-l+1);
            r++;
        }

        return ans;
    }

public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return helper(nums, k) - helper(nums, k-1);
    }
};