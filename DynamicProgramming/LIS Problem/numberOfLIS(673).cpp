class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> hash(n, 1);
        vector<int> count(n, 1);

        int maxAns = 1, maxInd = 0;
        for(int ind1 = 1; ind1 < n; ind1++){
            for(int ind2 = 0; ind2 < ind1; ind2++){
                if(nums[ind1] > nums[ind2]){
                    if(hash[ind1] < 1 + hash[ind2]){
                        hash[ind1] = 1 + hash[ind2];
                        count[ind1] = count[ind2];
                    }
                    else if(hash[ind1] == 1 + hash[ind2]){
                        count[ind1] += count[ind2];
                    }
                }
            }

            if(maxAns < hash[ind1]){
                maxAns = hash[ind1];
                maxInd = ind1;
            }
        }

        int ans = 0;
        for(int ind = 0; ind < hash.size(); ind++){
            if(hash[ind] == maxAns) ans += count[ind];
        }

        return ans;
    }
};