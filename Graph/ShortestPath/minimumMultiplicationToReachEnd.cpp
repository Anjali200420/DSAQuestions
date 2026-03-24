// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        int mod = 1e5;
        
        //Initial Configurations
        vector<int> dist(1e5, 1e9);
        queue<pair<int, int>> q;
        
        q.push({0, start});
        dist[start] = 0;
        
        while(!q.empty()){
            int node = q.front().second;
            int dis = q.front().first;
            
            q.pop();
            
            if(node == end) return dis;
            
            for(auto it : arr){
                int newMult = (it*node)%mod;
                if(dis + 1 < dist[newMult]){
                    dist[newMult] = dis + 1;
                    q.push({dist[newMult], newMult});
                }
            }
        }
        
        return -1;
    }
};
