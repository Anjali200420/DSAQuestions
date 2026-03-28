class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        // Creating Adjancy Matrix
        vector<vector<pair<int, int>>> adj(V);
        
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        
        // Prim's Algorithm
        // 1. Initial Configuration
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> vis(V, 0);
        
        pq.push({0, 0});
        
        // Core Logic
        int ans = 0;
        while(!pq.empty()){
            int node = pq.top().second;
            int wt = pq.top().first;
            
            pq.pop();
            
            if(!vis[node]){
                vis[node] = 1;
                ans += wt;
                
                for(auto it : adj[node]){
                    int adjNode = it.first;
                    int adjWt = it.second;
                    
                    if(!vis[adjNode]) pq.push({adjWt, adjNode});
                }
            }
        }
        
        return ans;
    }
};