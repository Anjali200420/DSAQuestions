class Solution {
  private:
    void dfs(int node, vector<int>& dist, vector<vector<int>>& adj){
        int dis = dist[node];
        
        for(auto it : adj[node]){
            if(dist[it] == -1 || dis + 1 < dist[it]){
                dist[it] = dis + 1;
                dfs(it, dist, adj);
            }
        }
    }
    
  public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
        // code here
        //Preparing an adjancy list
        vector<vector<int>> adj(V);
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        queue<int> q;
        vector<int> dist(V, -1);
        
        q.push(src);
        dist[src] = 0; 
        
        while(!q.empty()){
            int node = q.front();
            int wt = dist[node];
            
            q.pop();
            
            for(auto it : adj[node]){
                if(dist[it] == -1 || wt + 1 < dist[it]){
                    dist[it] = wt + 1;
                    q.push(it);
                }
            }
        }
        
        //dfs(src, dist, adj);
        
        return dist;
    }
};
