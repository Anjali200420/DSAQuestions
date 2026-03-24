class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();

        //Edge case
        for(int i = 0; i < n-1; i++){
            if(nums[i] > nums[i+1]){
                for(int j = i+1; j < n; j++){
                    if(nums[j] > nums[(j+1)%n]) return false;
                }
            }
        }

        return true;
    }
};