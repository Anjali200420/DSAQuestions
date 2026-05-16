class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();

        int max_element = nums[0];
        for(int ind = 1; ind < n; ind++){
            max_element = max(nums[ind], max_element);
        }

        if(n != max_element + 1) return false;
        
        vector<int> hash(max_element + 1, 0);
        for(int ind = 0; ind < n; ind++){
            if(nums[ind] == max_element && hash[nums[ind]-1]){
                hash[max_element] = 1;
                continue;
            } 

            hash[nums[ind]-1] = 1;
        }

        for(auto it : hash){
            if(it == 0) return false;
        }

        return true;
    }
};