class Solution {
  private:
    int timer = 0;
    void dfs(int node, int parent, vector<int>& vis, vector<int>& tin, vector<int>& low, vector<vector<int>>& adj, vector<int>& markNode){
        vis[node] = 1;
        tin[node] = low[node] = timer++;
        
        int child = 0;
        for(auto it : adj[node]){
            if(it == parent) continue;
            if(!vis[it]){
                dfs(it, node, vis, tin, low, adj, markNode);
                low[node] = min(low[node], low[it]);
                
                if(tin[node] <= low[it] && parent != -1) markNode[node] = 1;
                child++;
            }
            else{
                low[node] = min(low[node], tin[it]);
            }
        }
        
        if(child > 1 && parent == -1) markNode[node] = 1;
    }
    
  public:
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        // Code here
        // Creating Adjancy List
        vector<vector<int>> adj(V);
        
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> vis(V, 0);
        vector<int> tin(V, 0);
        vector<int> low(V, 0);
        vector<int> markNode(V, 0);
        
        for(int i = 0; i < V; i++){
            if(!vis[i]) dfs(i, -1, vis, tin, low, adj, markNode);
        }
        
        vector<int> articulationPoints;
        for(int i = 0; i < V; i++){
            if(markNode[i] == 1) articulationPoints.push_back(i);
        }
        
        if(articulationPoints.size() == 0) return {-1};
        return articulationPoints;
    }
};