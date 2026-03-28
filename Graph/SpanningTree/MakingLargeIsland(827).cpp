class DisjointSet {
private:
    vector<int> size, parent;

public:
    DisjointSet(int n){
        size.resize(n, 1);
        parent.resize(n);

        for(int i = 0; i < n; i++) parent[i] = i;
    }

    int ParentNodeSize(int node){
        return size[node];
    }

    int findUlParent(int x){
        if(parent[x] == x) return x;

        return parent[x] = findUlParent(parent[x]);
    }

    void unionBySize(int u, int v){
        int ulp_u = findUlParent(u);
        int ulp_v = findUlParent(v);

        if(ulp_u == ulp_v) return;
        if(size[ulp_u] >= size[ulp_v]){
            size[ulp_u] += size[ulp_v];
            parent[ulp_v] = ulp_u;
        }
        else{
            size[ulp_v] += size[ulp_u];
            parent[ulp_u] = ulp_v;
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
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int sz = n*m;

        DisjointSet ds(sz);
        vector<vector<int>> vis(n, vector<int>(m, 0));

        int delRow[4] = {-1, 0, 1, 0};
        int delCol[4] = {0, 1, 0, -1};

        // Finding the size of all the Islands present currently
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    int node = i*m + j;
                    vis[i][j] = 1;
                    
                    for(int k = 0; k < 4; k++){
                        int newRow = i + delRow[k];
                        int newCol = j + delCol[k];

                        if(isValid(newRow, newCol, n, m) && grid[newRow][newCol] == 1){
                            int adjNode = newRow*m + newCol;
                            if(ds.findUlParent(node) != ds.findUlParent(adjNode)){
                                ds.unionBySize(node, adjNode);
                            }
                        }
                    }
                }
            }
        }

        // Converting every zero to 1 and finding maximum size
        int ans = 0;
        for(int i = 0; i < sz; i++){
            ans = max(ans, ds.ParentNodeSize(i));
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                set<int> st;

                if(grid[i][j] == 0){
                    int node = i*m + j;

                    int tempAns = 0;
                    for(int k = 0; k < 4; k++){
                        int newRow = i + delRow[k];
                        int newCol = j + delCol[k];

                        if(isValid(newRow, newCol, n, m) && grid[newRow][newCol] == 1){
                            int adjNode = newRow*m + newCol;
                            st.insert(ds.findUlParent(adjNode));
                        }
                    }

                    for(auto it : st){
                        tempAns += ds.ParentNodeSize(it);
                    }

                    ans = max(tempAns+1, ans);
                }
            }
        }

        return ans;
    }
};