class Solution {
public:
    int minFallingSum(int i, int j, int m, vector<vector<int>>& matrix) {
        if (j < 0 || j >= m)
            return 1e9;
        if (i == 0)
            return matrix[0][j];

        int up = matrix[i][j] + minFallingSum(i - 1, j, m, matrix);
        int dl = matrix[i][j] + minFallingSum(i - 1, j - 1, m, matrix);
        int dr = matrix[i][j] + minFallingSum(i - 1, j + 1, m, matrix);

        return min(up, min(dl, dr));
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int mini = 1e9;

        for (int j = 0; j < n; j++) {
            mini = min(mini, minFallingSum(m - 1, j, n, matrix));
        }

        return mini;
    }
};
