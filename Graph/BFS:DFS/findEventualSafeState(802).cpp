class Solution {
private:
    bool dfs(int node, vector<int>& vis, vector<int>& pathVis, vector<int>& ans, vector<vector<int>>& graph){
        vis[node] = 1;
        pathVis[node] = 1;

        for(auto it : graph[node]){
            if(!vis[it]){
                if(dfs(it, vis, pathVis, ans, graph)) return true;
            } 
            else if(pathVis[it]) return true;
        }

        ans.push_back(node);
        pathVis[node] = 0;
        return false;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();

        vector<int> vis(V, 0);
        vector<int> pathVis(V, 0);
        vector<int> ans;

        for(int i = 0; i < V; i++){
            if(!vis[i]){
                dfs(i, vis, pathVis, ans, graph);
            }
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};