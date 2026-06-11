class Solution {
private:
    int maxDepth = 0;
    long long mod = 1e9 + 7;

    long long power(long long base, long long exp){
        long long res = 1;
        base %= mod;

        while(exp > 0){
            if(exp % 2 != 0) res =  (res*base)%mod;
            base = (base*base)%mod;
            exp /= 2;
        }

        return res;
    }

    void dfs(int node, int parent, int currentDepth, vector<vector<int>>& adj){
        maxDepth = max(maxDepth, currentDepth);

        for(auto it : adj[node]){
            if(it != parent){
                dfs(it, node, currentDepth + 1, adj);
            }
        }
    }

public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        long long mod = 1e9 + 7;

        // 1. Calculating the Maximum Height
        vector<vector<int>> adj(n+1);
        for(auto& it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        dfs(1, 0, 0, adj);

        // 2. Calculating the numbers of ways of odd one
        if(maxDepth == 0) return 0;
        return power(2, (maxDepth-1));
    }
};