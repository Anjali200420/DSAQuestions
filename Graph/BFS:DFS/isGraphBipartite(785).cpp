class Solution {
private:
    // bool bfs(int node, int parent, vector<int>& color, vector<vector<int>>& graph){
    //     queue<pair<int, int>> q;

    //     q.push({node, parent});
    //     color[node] = 0;

    //     while(!q.empty()){
    //         int node = q.front().first;
    //         int parent = q.front().second;

    //         q.pop();

    //         for(auto it : graph[node]){
    //             if(color[it] == -1){
    //                 color[it]  = !color[node];
    //                 q.push({it, node});
    //             }
    //             else{
    //                 if(color[it] == color[node]) return false;
    //             }
    //         }
    //     }

    //     return true;
    // }

    bool dfs(int node, int parent, int col, vector<int>& color, vector<vector<int>>& graph){
        color[node] = col;

        for(auto it : graph[node]){
            if(color[it] == -1){
                if(dfs(it, node, !col, color, graph) == false) return false;
            }
            else{
                if(color[it] == color[node]) return false;
            }
        }

        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();

        vector<int > color(V, -1);

        for(int i = 0; i < V; i++){
            if(color[i] == -1){
                if(dfs(i, -1, 0, color, graph) == false) return false;
            }
        }

        return true;
    }
};