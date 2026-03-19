class Solution {
private:
    void dfsTraversal(int node, vector<int>& vis, vector<vector<int>>& adj){
        vis[node] = 1;

        for(auto it : adj[node]){
            if(!vis[it]){
                dfsTraversal(it, vis, adj);
            }
        }
    }

    void bfsTraversal(int node, vector<int>& vis, vector<vector<int>>& adj){
        queue<int>  q;
        
        q.push(node);
        vis[node] = 1;

        while(!q.empty()){
            int currNode = q.front(); q.pop();

            for(auto it : adj[currNode]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int nodes = isConnected.size();

        vector<vector<int>> adj(nodes);

        for(int i = 0; i < nodes; i++){
            for(int j = 0; j < nodes; j++){
                if(isConnected[i][j] == 1 && i != j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<int> vis(nodes, 0);

        int ans = 0;
        for(int i = 0; i < nodes; i++){
            if(!vis[i]){
                ans++;
                bfsTraversal(i, vis, adj);
            }
        }

        return ans;
    }
};