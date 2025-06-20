class Solution {
    const int drow[4] = {-1, 0, 1, 0};
    const int dcol[4] = { 0, 1, 0,-1};

    void dfs(int r, int c,
             int iniColor,
             vector<vector<int>>& image,
             vector<vector<int>>& ans,
             int newColor)
    {
        ans[r][c] = newColor;              

        for (int k = 0; k < 4; ++k) {
            int nr = r + drow[k];
            int nc = c + dcol[k];

            if (nr >= 0 && nr < (int)image.size() &&
                nc >= 0 && nc < (int)image[0].size() &&
                image[nr][nc] == iniColor &&
                ans[nr][nc] != newColor)         
            {
                dfs(nr, nc, iniColor, image, ans, newColor);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                  int sr, int sc,
                                  int newColor)
    {
        int iniColor = image[sr][sc];
        if (iniColor == newColor)               
            return image;

        vector<vector<int>> ans = image;     
        dfs(sr, sc, iniColor, image, ans, newColor);
        return ans;
    }
};
