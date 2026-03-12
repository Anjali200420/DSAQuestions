class Solution {
private:
    int helper(vector<int>& nums, int goal){
        if(goal < 0) return 0;
        
        int ans = 0;

        int l = 0, r = 0, cnt = 0;
        while(r < nums.size()){
            cnt += nums[r];

            while(cnt > goal){
                cnt -= nums[l];
                l++;
            }

            ans += (r-l+1);

            r++;
        }

        return ans;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return helper(nums, goal) - helper(nums, goal-1);
    }
};