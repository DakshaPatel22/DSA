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
       for(int j=0;j<m;j++)
       {
        dp[0][j]=matrix[0][j];// base cases ki value daalo top row mein
       }
       for(int i=1;i<n;i++)
       {
        for(int j=0;j<m;j++)
       {
       int up=matrix[i][j]+dp[i-1][j];
        int dl=matrix[i][j];
        if(j-1>0)
      dl=dl+dp[i-1][j-1];
      else
      dl=dl+1e9;
      int dr=matrix[i][j];
       if(j+1<m)
        dr=dr+dp[i-1][j+1];
        else
        dr=dr+1e9;
         dp[i][j]= min(up, min(dl, dr));
       }
       }
       int ans=dp[n-1][0];
       for(int j=0;j<m;j++)
       {
        ans=min(ans, dp[n-1][j]);
       }
       return ans;
    }
};

