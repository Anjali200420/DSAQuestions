class Solution {
  private:
    void dfs(int node, bool flag, stack<int>& st, vector<int>& vis, vector<vector<int>>& adj){
        vis[node] = 1;
        
        for(auto it : adj[node]){
            if(!vis[it]) dfs(it, flag, st, vis, adj);
        }
        
        if(flag) st.push(node);
    }
    
  public:
    int kosaraju(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adj(V);
        
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            
            adj[u].push_back(v);
        }
        
        vector<int> vis(V, 0);
        stack<int> st;
        
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                dfs(i, true, st, vis, adj);
            }
        }
        
        vector<vector<int>> revAdj(V);
        fill(vis.begin(), vis.end(), 0);
        
        for(int node = 0; node < V; node++){
            for(auto it : adj[node]){
                revAdj[it].push_back(node);
            }
        }
        
        int ans = 0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            
            if(!vis[node]){
                ans++;
                dfs(node, false, st, vis, revAdj);
            }
        }
        
        return ans;
    }
};