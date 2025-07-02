const int MOD = 1e9 + 7;

class Solution {
public:
    int countPaths(int totalNodes, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(totalNodes);  

        for(auto it: roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dis(totalNodes, 1e9);
        vector<int> ways(totalNodes, 0);

        dis[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        while(!pq.empty()) {
            auto it = pq.top();
            
            int node = it.second;
            int dist = it.first;
pq.pop();
            for(auto iter : adj[node]) {
                int adjNode = iter.first;
                int edw = iter.second;

                if(dist + edw < dis[adjNode]) {
                    dis[adjNode] = dist + edw;
                    ways[adjNode] = ways[node];
                    pq.push({dis[adjNode], adjNode});
                }
                else if(dist + edw == dis[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % MOD;
                }
            }
        }

        return ways[totalNodes - 1] % MOD;
    }
};

