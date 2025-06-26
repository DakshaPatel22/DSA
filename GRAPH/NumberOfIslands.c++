class Solution {
    private:
    void bfs(int r, int c, vector<vector<int>> &v, vector<vector<char>> &g) {
        v[r][c] = 1;
        queue<pair<int, int>> q;
        q.push({r, c});

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int dr = -1; dr <= 1; dr++) {
                for (int dc = -1; dc <= 1; dc++) {
                    int nr = row + dr;
                    int nc = col + dc;

                    if (nr >= 0 && nr < g.size() && nc >= 0 && nc < g[0].size() &&
                        !v[nr][nc] && g[nr][nc] == 'L') {
                        v[nr][nc] = 1;
                        q.push({nr, nc});
                    }
                }
            }
        }
    }
  public:
    int countIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int c = 0;

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == 'L') {
                    c++;
                    bfs(i, j, vis, grid);
                }
            }
        }

        return c;
        
    }
};