class Solution {
public:
    int minFallingSum(int i, int j, int m, vector<vector<int>>& matrix, vector<vector<int>> & dp) {
        if (j < 0 || j >= m)
            return 1e9;
        if (i == 0)
            return matrix[0][j];
        if(dp[i][j]!=-1)
        return dp[i][j];

        int up = matrix[i][j] + minFallingSum(i - 1, j, m, matrix, dp);
        int dl = matrix[i][j] + minFallingSum(i - 1, j - 1, m, matrix, dp);
        int dr = matrix[i][j] + minFallingSum(i - 1, j + 1, m, matrix, dp);

        return dp[i][j]=min(up, min(dl, dr));
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int mini = 1e9;
         vector<vector<int>> dp(m, vector<int>(n, -1));
        for (int j = 0; j < n; j++) {
            mini = min(mini, minFallingSum(m - 1, j, n, matrix, dp));
        }

        return mini;
    }
};
