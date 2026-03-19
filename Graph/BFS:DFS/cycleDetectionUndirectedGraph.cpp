class Solution {
  private:
    bool dfs(int node, int parent, vector<int>& vis, vector<vector<int>>& adj){
        vis[node] = 1;
        
        for(auto it : adj[node]){
            if(!vis[it]){
                if(dfs(it, node, vis, adj)) return true;
            }
            else{
                if(it != parent) return true;
            }
        }
        
        return false;
    }
    
    // bool bfs(int node, vector<int>& vis, vector<vector<int>>& adj){
    //     queue<pair<int, int>> q;
        
    //     vis[node] = 1;
    //     q.push({node, -1});
        
    //     while(!q.empty()){
    //         int node = q.front().first;
    //         int parent = q.front().second;
            
    //         q.pop();
            
    //         for(auto it : adj[node]){
    //             if(!vis[it]){
    //                 vis[it] = 1;
    //                 q.push({it, node});
    //             }
    //             else{
    //                 if(it != parent) return true;
    //             }
    //         }
    //     }
        
    //     return false;
    // }
    
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> vis(V, 0);
        
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                if(dfs(i, -1, vis, adj)) return true;
            }
        }
        
        return false;
    }
};