class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans = 0;

        int l = 0, r = 0;
        int cntZeroes = 0;
        while(r < nums.size()){
            if(nums[r] == 0) cntZeroes++;
            
            if(cntZeroes > k){
                if(nums[l] == 0) cntZeroes--;
                l++;
            }

            ans = max(ans, r-l+1);
            r++;
        }

        return ans;
    }
};