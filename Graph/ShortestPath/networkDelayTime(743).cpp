class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Creating Adjancy List
        vector<vector<pair<int, int>>> adj(n+1);

        for(auto it : times){
            int u = it[0];
            int v = it[1];
            int time = it[2];

            adj[u].push_back({v, time});
        }

        // Initial Configurations
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> time(n+1, -1);

        pq.push({0, k});
        time[k] = 0;

        // Core Dijkstra Logic
        while(!pq.empty()){
            int tim = pq.top().first;
            int node = pq.top().second;

            pq.pop();

            for(auto it : adj[node]){
                int adjNode = it.first;
                int adjTime = it.second;

                if(time[adjNode] == -1 || tim + adjTime < time[adjNode]){
                    time[adjNode] = tim + adjTime;

                    pq.push({time[adjNode], adjNode});
                }
            }
        }

        int ans = -1;
        for(int i = 1; i < time.size(); i++){
            if(time[i] == -1) return -1;
            ans = max(ans, time[i]);
        }

        return ans;
    }
};