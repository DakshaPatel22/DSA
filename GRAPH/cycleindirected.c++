class Solution {
private:
    bool dfs(int node, vector<int> &vis, vector<int> &pv, vector<vector<int>> &adj) {
        vis[node] = 1;
        pv[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                if (dfs(it, vis, pv, adj))
                    return true;
            }
            else if (pv[it]) {
                return true;
            }
        }
        pv[node] = 0;
        return false;
    }

public:
    bool isCyclic(int V, vector<vector<int>> &adj) {
        vector<int> vis(V, 0);
        vector<int> pathVisited(V, 0);
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (dfs(i, vis, pathVisited, adj))
                    return true;
            }
        }
        return false;
    }
};
