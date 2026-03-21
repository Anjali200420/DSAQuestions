class Solution {
private:
    bool dfs(int node, vector<int>& vis, vector<int>& pathVis, stack<int>& st, vector<vector<int>>& adj){
        vis[node] = 1;
        pathVis[node] = 1;

        for(auto it : adj[node]){
            if(!vis[it]){
                if(dfs(it, vis, pathVis, st, adj)) return true;
            }
            else if(pathVis[it]) return true;
        }

        st.push(node);
        pathVis[node] = 0;

        return false;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        for(auto it : prerequisites){
            int u = it[1];
            int v = it[0];

            adj[u].push_back(v);
            indegree[v]++;
        }

        // vector<int> vis(numCourses, 0);
        // vector<int> pathVis(numCourses, 0);
        // stack<int> st;

        // for(int i = 0; i < numCourses; i++){
        //     if(!vis[i]){
        //         if(dfs(i, vis, pathVis, st, adj)) return {};
        //     }
        // }

        // vector<int> ans;
        // while(!st.empty()){
        //     ans.push_back(st.top());
        //     st.pop();
        // }

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

        if(ans.size() == numCourses) return ans;
        return {};
    }
};