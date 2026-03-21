class Solution {
  private:
    // void dfs(int node, vector<int>& vis, stack<int>& st, vector<vector<int>>& adj){
    //     vis[node] = 1;
        
    //     for(auto it : adj[node]){
    //         if(!vis[it]) dfs(it, vis, st, adj);
    //     }
        
    //     st.push(node);
    // }
    
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V);
        vector<int> indegree(V, 0);
        
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            
            adj[u].push_back(v);
            indegree[v]++;
        }
        
        queue<int> q;
        for(int i = 0; i < V; i++){
            if(indegree[i] == 0){
                q.push(i);
            } 
        }
        
        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            ans.push_back(node);
            
            for(auto it : adj[node]){
                if(--indegree[it] == 0){
                    q.push(it);
                } 
            }
        }
        
        return ans;
    }
};