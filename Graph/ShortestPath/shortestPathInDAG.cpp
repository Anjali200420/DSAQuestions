// User function Template for C++
class Solution {
  private:
    void toposort(int node, vector<int>& vis, stack<int>& st, vector<vector<pair<int,int>>>& adj){
        vis[node] = 1;
        
        for(auto it : adj[node]){
            int adjNode = it.first;
            if(!vis[adjNode]) toposort(adjNode, vis, st, adj);
        }
        
        st.push(node);
    }
    
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        //Creating an Adjancy Matrix
        vector<vector<pair<int, int>>> adj(V);
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            
            adj[u].push_back({v, wt});
        }
        
        //Applying the toposort algorithm
        vector<int> vis(V, 0);
        stack<int> st;
        for(int i = 0; i < V; i++){
            if(!vis[i]) toposort(i, vis, st, adj);
        }
        
        //Finding the shortest distance by relaxing the nodes one by one.
        vector<int> dist(V, -1);
        dist[0] = 0;
        while(!st.empty()){
            int node = st.top();
            int dis = dist[node];
            st.pop();
            
            if(dis == -1) continue;
            
            for(auto it : adj[node]){
                int adjNode = it.first;
                int adjWt = it.second;
                
                if(dist[adjNode] == -1 || dis + adjWt < dist[adjNode]){
                    dist[adjNode] = dis + adjWt;
                }
            }
        }
        
        return dist;
    }
};
