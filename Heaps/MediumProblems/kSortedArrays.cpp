// User function template for C++

class Solution {
  public:
    string isKSortedArray(int arr[], int n, int k) {
        // code here.
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        
        for(int i = 0; i <= min(k, n-1); i++){
            minHeap.push({arr[i], i});
        }
        
        vector<int> sortedArr;
        int ind = 0;
        for(int j = k+1; j < n; j++){
            if(abs(minHeap.top().second - ind) > k) return "No";
            ind++;
            
            sortedArr.push_back(minHeap.top().first);
            minHeap.pop();
            
            minHeap.push({arr[j], j});
        }
        
        while(!minHeap.empty()){
            if(abs(minHeap.top().second - ind) > k) return "No";
            ind++;
            
            sortedArr.push_back(minHeap.top().first);
            minHeap.pop();
        }
        
        for(int ind = 0; ind < n-1; ind++){
            if(sortedArr[ind] > sortedArr[ind+1]) return "No";
        }
        
        return "Yes";
    }
};