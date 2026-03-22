class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        //Trying can be make even array
        bool evenPossible = true;
        for(int i = 0; i < nums1.size(); i++){
            if(nums1[i]%2 == 0) continue;
            else{
                bool flag = false;
                for(int j = 0; j < nums1.size(); j++){
                    if(j != i){
                        if((nums1[i] - nums1[j])%2 == 0){
                            flag = true;
                            break;
                        }
                    }
                }

                if(flag == false){
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
                bool flag = false;
                for(int j = 0; j < nums1.size(); j++){
                    if(j != i){
                        if((nums1[i] - nums1[j])%2 != 0){
                            flag = true;
                            break;
                        }
                    }
                }

                if(flag == false){
                    oddPossible = false;
                    break;
                }
            }
        }

        return oddPossible ? true : false;
    }
};©leetcode