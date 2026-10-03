class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        const long long MOD = 1e9 + 7;
        for(auto& e: roads){
            int u = e[0];
            int v = e[1];
            int wt = e[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        

        priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<pair<long long, long long>>> pq;
        vector<long long> dist(n, LLONG_MAX);
        vector<long long> ways(n, 0);
        ways[0] = 1;
        dist[0] = 0;
        pq.push({0,0});
        while(!pq.empty()){
            int u = pq.top().second;
            long long d = pq.top().first;
            pq.pop();

            for(auto& e : adj[u]){
                int v = e.first;
                int w = e.second;
                if(dist[v] > d + w){
                    dist[v] = d + w;
                    ways[v] = ways[u];
                    pq.push({dist[v], v});
                }
                else if(dist[v] == d + w){
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }

        int ans = ways[n-1];
        return ans;
    }
};