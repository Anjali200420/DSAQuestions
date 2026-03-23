class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //Creating the Adjancy list
        vector<vector<pair<int, int>>> adj(n);

        for(auto flight : flights){
            int u = flight[0];
            int v = flight[1];
            int wt = flight[2];

            adj[u].push_back({v, wt});
        }

        // Finding the shortest distance withing k stops('k' must be priority here)
        priority_queue<pair<pair<int, int>, int> , vector<pair<pair<int, int>, int>>, greater<pair<pair<int, int>, int>>> pq;        // {{k, price}, node}
        vector<int> price(n, -1);  // Vector to find the cheapest price for the individual nodes from the source;

        //Initial Initialization
        pq.push({{0, 0}, src});
        price[src] = 0;

        // Implementing the core logic of the Dijkstra algorithm
        while(!pq.empty()){
            int stops = pq.top().first.first;
            int pric = pq.top().first.second;

            int node = pq.top().second;
            pq.pop();

            if(stops > k) continue;

            for(auto it : adj[node]){
                int adjNode = it.first;
                int adjPrice = it.second;

                if(price[adjNode] == -1 || pric + adjPrice < price[adjNode]){
                    price[adjNode] = pric + adjPrice;

                    pq.push({{stops+1, price[adjNode]}, adjNode});
                }
            }
        }


        return price[dst];
    }
};