class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        //Trying can be make even array
        int oddSmallest = INT_MAX;

        for(int i = 0; i < nums1.size(); i++){
            if(nums1[i] % 2 == 0) continue;
            oddSmallest = min(oddSmallest, nums1[i]);
        }
        
        bool evenPossible = true;
        for(int i = 0; i < nums1.size(); i++){
            if(nums1[i]%2 == 0) continue;
            else{
                if(oddSmallest != INT_MAX && (nums1[i] - oddSmallest) >= 1) continue;
                else{
                    evenPossible = false;
                    break;
                }
            } 
        }

        if(evenPossible) return true;

        // Trying can be odd array
        bool oddPossible = true;
        for(int i = 0; i < nums1.size(); i++){
            if(nums1[i]%2 != 0) continue;
            else{
                if(oddSmallest != INT_MAX && (nums1[i] - oddSmallest) >= 1) continue;
                else{
                    oddPossible = false;
                    break;
                }
            }
        }

        return oddPossible ? true : false;
    }
};©leetcode