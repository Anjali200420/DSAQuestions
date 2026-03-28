class DisjointSet {
    private:
        vector<int> rank, parent;
    public: 
        DisjointSet(int V){
            rank.resize(V, 0);
            parent.resize(V, 0);
            
            for(int i = 0; i < V; i++) parent[i] = i;
        }
        
        int findUltimateParent(int x){
            if(parent[x] == x) return x;
            
            return parent[x] = findUltimateParent(parent[x]);
        }
        
        void findUnion(int x, int z){
            int ulp_x = findUltimateParent(x);
            int ulp_z = findUltimateParent(z);
            
            if(rank[ulp_x] > rank[ulp_z]) parent[ulp_z] = ulp_x;
            else if(rank[ulp_x] < rank[ulp_z]) parent[ulp_x] = ulp_z;
            else{
                parent[ulp_z] = ulp_x;
                rank[ulp_x] += 1;
            }
        }
};

class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        // Performing sorting according to the weight
        int totalEdges = edges.size();
        vector<pair<int, pair<int, int>>> adj(totalEdges);
        
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            
            adj.push_back({wt, {u, v}});
        }
        
        sort(adj.begin(), adj.end());
        
        DisjointSet ds();
        
        int ans = 0;
        for(auto it : adj){
            int u = it.second.first;
            int v = it.second.second;
            
            int ulp_u = ds.findUltimateParent(u);
            int ulp_v = ds.findUltimateParent(v);
            
            if(ulp_u != ulp_v){
                ans += it.first;
                
                ds.findUnion(ulp_u, ulp_v);
            }
        }
        
        return ans;
    }
};