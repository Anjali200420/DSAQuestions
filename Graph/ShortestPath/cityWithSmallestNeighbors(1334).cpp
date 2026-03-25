class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // Creating adjancy matrix to apply the floyd warshall algorithm
        vector<vector<int>> dist(n, vector<int>(n, 1e8));

        for(int i = 0; i < n; i++){
            dist[i][i] = 0;
        }

        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            dist[u][v] = wt;
            dist[v][u] = wt;
        }

        for(int via = 0; via < n; via++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    dist[i][j] = min(dist[i][j], (dist[i][via] + dist[via][j]));
                }
            }
        }

        int cntMax = INT_MAX;
        int cntInd = -1;
        for(int i = 0; i < n; i++){
            int cnt = 0;
            for(int j = 0; j < n; j++){
                if(dist[i][j] <= distanceThreshold) cnt++;
            }

            if(cntMax >= cnt){
                cntMax = cnt;
                cntInd = i;
            }
        }

        return cntInd;
    }
};