class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        //Creating Adjancy List
        vector<vector<pair<int, int>>> adj(V);
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        
        //Applying the Dijkstra Algorithm
        //priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        set<pair<int, int>> st;
        vector<int> dist(V, -1);
        
        //pq.push({0, src});
        st.insert({0, src});
        dist[src] = 0;
        
        while(!st.empty()){
            // int node = pq.top().second;
            // int dis = pq.top().first;
            
            // pq.pop();
            auto it = st.begin();
            int node = it -> second;
            int dis = it -> first;
            
            st.erase(it);
            
            for(auto it : adj[node]){
                int adjNode = it.first;
                int adjWt = it.second;
                
                // if(dist[adjNode] == -1 || dis + adjWt < dist[adjNode]){
                //     dist[adjNode] = dis + adjWt;
                //     pq.push({dist[adjNode], adjNode});
                // }
                
                if(dist[adjNode] == -1){
                    dist[adjNode] = dis + adjWt;
                    st.insert({dist[adjNode], adjNode});
                }
                else if(dis + adjWt < dist[adjNode]){
                    st.erase({dist[adjNode], adjNode});
                    
                    dist[adjNode] = dis + adjWt;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }
        
        return dist;
    }
};