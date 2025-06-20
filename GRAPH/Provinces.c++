class Solution {
private:
    void dfs(vector<int>& va, int node, vector<vector<int>>& adjsL)
    {
        va[node] = 1;
        for (auto it : adjsL[node]) {
            if (!va[it]) {
                dfs(va, it, adjsL);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected)
    {
        int n = isConnected.size();
        vector<vector<int>> adsL(n);

        // Create adjacency list from matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adsL[i].push_back(j);
                }
            }
        }

        vector<int> vis(n, 0);
        int c = 0;

        // Count provinces using DFS
        for (int i = 0; i < n; i++) {
            if (vis[i] == 0) {
                dfs(vis, i, adsL);
                c++;
            }
        }

        return c;
    }
};
