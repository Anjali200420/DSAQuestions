class DisjointSet {
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

    void findUnion(int u, int v){
        int ulp_u = findUlParent(u);
        int ulp_v = findUlParent(v);

        if(ulp_u == ulp_v) return;

        if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }
        else if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

class Solution {
private:
    bool isValid(int row, int col, int n, int m){
        if((row >= 0 && row < n) && (col >= 0 && col < m)) return true;
        return false;
    }

public:
    int swimInWater(vector<vector<int>>& grid) {
        int n =  grid.size();
        int m = grid[0].size();

        DisjointSet ds(n*m);

        vector<tuple<int, int, int>> helper;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                helper.push_back({grid[i][j], i, j});
            }
        }

        sort(helper.begin(), helper.end());

        vector<bool> vis(n*m, false);
        for(auto &[height, row, col] : helper){
            int node1 = row * m + col;
            vis[node1] = true;

            int delRow[4] = {-1, 0, 1, 0};
            int delCol[4] = {0, 1, 0, -1};

            for(int i = 0; i < 4; i++){
                int newRow = row + delRow[i];
                int newCol = col + delCol[i];

                int node2 = newRow*m + newCol;
                if(isValid(newRow, newCol, n, m) && vis[node2]){
                    ds.findUnion(node1, node2);
                }
            }

            if(ds.findUlParent(0) == ds.findUlParent(n*m-1)) return height;
        }

        return -1;
    }
};