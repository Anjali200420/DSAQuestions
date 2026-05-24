// User function Template for C++

class Solution {
  public:
    vector<int> replaceWithRank(vector<int> &arr, int N) {
        vector<int> sortedArr(N);
        sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());
        
        map<int, int> mpp;
        int rank = 1;
        for(auto it : sortedArr){
            if(mpp.find(it) == mpp.end()){
                mpp[it] = rank; 
                rank++;
            }
        }
        
        vector<int> ans(N);
        for(int ind = 0; ind < N; ind++){
            ans[ind] = mpp[arr[ind]];
        }
        
        return ans;
    }
};
