class DisjointSet {
private:
    vector<int> sz;
    vector<int> parent;

public:
    DisjointSet(int n){
        sz.resize(n, 1);
        parent.resize(n);

        for(int i = 0; i < n; i++) parent[i] = i;
    }

    int findUlParent(int x){
        if(parent[x] == x) return x;

        return parent[x] = findUlParent(parent[x]);
    }

    void unionBySize(int x, int z){
        int ulp_x = findUlParent(x);
        int ulp_z = findUlParent(z);

        if(ulp_x == ulp_z) return;

        if(sz[ulp_x] >= sz[ulp_z]){
            parent[ulp_z] = ulp_x;
            sz[ulp_x] += sz[ulp_z];

        }
        else{
            parent[ulp_x] = ulp_z;
            sz[ulp_z] += sz[ulp_x];
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int totalRow = 0;
        int totalCol = 0;

        for(auto it : stones){
            totalRow = max(totalRow, it[0]);
            totalCol = max(totalCol, it[1]);
        }

        DisjointSet ds(totalRow + totalCol + 2);

        for(auto it : stones){
            ds.unionBySize(it[0], totalRow + it[1] + 1);
        }

        set<int> uniqueParents;
        for(auto it : stones){
            int ulp_row = ds.findUlParent(it[0]);
            int ulp_col = ds.findUlParent(totalRow + it[1] + 1);

            uniqueParents.insert(ulp_row);
            uniqueParents.insert(ulp_col);
        }

        int distinctComponents = uniqueParents.size();
        return stones.size() - distinctComponents;
    }
};