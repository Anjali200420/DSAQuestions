class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        int ans = 0;
        for(int ind1 = 0; ind1 < n1; ind1++){
            int low = ind1, high = n2-1;
            while(low <= high){
                int mid = (low + high) / 2;

                if(nums1[ind1] <= nums2[mid]){
                    low = mid + 1;
                }
                else high = mid - 1;
            }

            if(high >= ind1) ans = max(ans, high - ind1);
        }

        return ans;
    }
};