class DisjointSet{
private:
    vector<int> rank, parent;

public:
    DisjointSet(int n){
        rank.resize(n, 0);
        parent.resize(n);

        for(int i = 0; i < n; i++) parent[i] = i;
    }

    int findUlParent(int x){
        if(parent[x] == x) return x;

        return parent[x] = findUlParent(parent[x]);
    }

    void findUnion(int x, int z){
        int ulp_x = findUlParent(x);
        int ulp_z = findUlParent(z);

        if(rank[ulp_x] > rank[ulp_z]) parent[ulp_z] = ulp_x;
        else if(rank[ulp_x] < rank[ulp_z]) parent[ulp_x] = ulp_z;
        else{
            parent[ulp_z] = ulp_x;
            rank[ulp_x]++;
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);

        int extraEdges = 0;
        for(auto it : connections){
            int u = it[0];
            int v = it[1];

            int ulp_u = ds.findUlParent(u);
            int ulp_v = ds.findUlParent(v);
            
            if(ulp_u == ulp_v) extraEdges++;
            else{
                ds.findUnion(u, v);
            }
        }

        int distinctComponents = 0;
        for(int i = 0; i < n; i++){
            if(ds.findUlParent(i) == i) distinctComponents++;
        }

        int reqEdges = distinctComponents - 1;

        if(extraEdges < reqEdges) return -1;
        return reqEdges;
    }
};