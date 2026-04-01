// User function Template for C++

class Solution {
  private:
    bool fun(int ind, int n , vector<int>& arr){
        if(ind == n-1) return true;
        if(ind >= n || arr[ind] == 0) return false;
        
        for(int j = ind+1; j <= ind + arr[ind]; j++){
            if(fun(j, n, arr)) return true;
        }
        
        return false;
    }
    
  public:
    // Function to check if we can reach the last index from 0th index.
    // bool canReach(vector<int> &arr) {
    //     // code here
    //     int n = arr.size();
        
    //     return fun(0, n, arr, dp);
    // }

    bool canReach(vector<int> &arr) {
        // code here
        int n = arr.size();
        
        int destination = n-1;
        for(int i = n-2; i >= 0; i--){
            if(i + arr[i] >= destination) destination = i;
        }
        
        return destination == 0;
    }
};