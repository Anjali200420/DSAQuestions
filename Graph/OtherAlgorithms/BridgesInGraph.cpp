class Solution {
public:
    int timer = 0;

    void dfs(int node, int parent, vector<int>& vis, vector<int>& tin, vector<int>& low, vector<vector<int>>& adj, vector<vector<int>>& bridges){
        vis[node] = 1;
        tin[node] = timer;
        low[node] = timer;

        timer++;

        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it, node, vis, tin, low, adj, bridges);
                low[node] = min(low[node], low[it]);

                if(tin[node] < low[it]){
                    bridges.push_back({node, it});
                }
            }
            else if(it != parent){
                low[node] = min(low[node], low[it]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);

        for(auto it : connections){
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> tin(n, 0);
        vector<int> low(n, 0);
        vector<int> vis(n, 0);

        vector<vector<int>> bridges;

        for(int i = 0; i < n; i++){
            if(!vis[i]) dfs(i, -1, vis, tin, low, adj, bridges);
        }

        return bridges;
    }
};