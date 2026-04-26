class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
         int n = nums.size();

        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(i == 0  || i == n-1){
                ans.push_back(nums[i]);
                continue;
            } 

            bool leftSide = true;
            for(int j = 0; j < i; j++){
                if(nums[j] >= nums[i]) leftSide = false;
            }

            bool rightSide = true;
            for(int j = i+1; j < n; j++){
                if(nums[j] >= nums[i]) rightSide = false;
            }

            if(leftSide || rightSide) ans.push_back(nums[i]);
        }

        return ans;
    }
};