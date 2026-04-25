class Solution {
  public:
    vector<int> getLIS(vector<int>& arr) {
        // Code here
        int n = arr.size();
        
        vector<int> prev_ind(n, 1);
        vector<int> hash(n);
        
        for(int ind = 0; ind < n; ind++) hash[ind] = ind;
        
        int maxi = 1, maxInd = 0;
        for(int ind1 = 1; ind1 < n; ind1++){
            for(int ind2 = 0; ind2 < ind1; ind2++){
                if(arr[ind2] < arr[ind1]){
                    if((1 + prev_ind[ind2] > prev_ind[ind1])){
                        prev_ind[ind1] = 1 + prev_ind[ind2];
                        
                        hash[ind1] = ind2;
                    }
                }
            }
            
            if(maxi < prev_ind[ind1]){
                maxi = prev_ind[ind1];
                maxInd = ind1;
            }
        }
        
        vector<int> ans;
        while(hash[maxInd] != maxInd){
            ans.push_back(arr[maxInd]);
            
            maxInd = hash[maxInd];
        }
        
        ans.push_back(arr[maxInd]);
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};