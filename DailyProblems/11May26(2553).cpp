class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans;
        for(int ind = 0; ind < n; ind++){
            int num = nums[ind];

            vector<int> temp;
            while(num){
                int digit = num % 10;
                temp.push_back(digit);

                num /= 10;
            }

            reverse(temp.begin(), temp.end());
            for(auto it : temp){
                ans.push_back(it);
            }
        }

        return ans;
    }
};