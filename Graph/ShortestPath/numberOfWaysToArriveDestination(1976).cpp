class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod = 1e9 + 7;

        //Creating adjancy list
        vector<vector<pair<int, int>>> adj(n);

        for(auto it : roads){
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        // Applying core Dijkstra logic

        //Initial Configuration
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        vector<long long> times(n, LLONG_MAX);   //For finding the shortest time from the source node
        vector<int> ways(n, 0);    // Number of ways till that node from source node

        pq.push({0, 0});
        times[0] = 0;
        ways[0] = 1;

        // Main Logic
        while(!pq.empty()){
            int node = pq.top().second;
            long long time = pq.top().first;

            pq.pop();

            for(auto it : adj[node]){
                int adjNode = it.first;
                long long adjTime = it.second;

                long long newTime = time + adjTime;

                if(newTime < times[adjNode]){
                    times[adjNode] = newTime;
                    pq.push({newTime, adjNode});
                    ways[adjNode] = ways[node];
                }
                else if(times[adjNode] == newTime){
                    ways[adjNode] = (ways[adjNode] + ways[node])%mod;
                }
            }
        }

        if(ways[n-1] == 0) return -1;
        return ways[n-1]%mod;
    }
};