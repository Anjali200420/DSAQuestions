class Solution {
private:
    bool dfs(int node, vector<int>& vis, vector<int>& pathVis, vector<vector<int>>& adj){
        vis[node] = 1;
        pathVis[node] = 1;

        for(auto it : adj[node]){
            if(!vis[it]){
                if(dfs(it, vis, pathVis, adj)) return true;
            } 
            else if(pathVis[it]) return true;
        }

        pathVis[node] = 0;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for(auto it : prerequisites){
            int u = it[1];
            int v = it[0];

            adj[u].push_back(v);
            indegree[v]++;
        }

        
        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0) q.push(i);
        }

        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();

            ans.push_back(node);

            for(auto it : adj[node]){
                if(--indegree[it] == 0) q.push(it);
            }
        }

        return (ans.size() == numCourses) ? true : false;
    }
};