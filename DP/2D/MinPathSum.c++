class Solution {
    public :
    int minSum(int m,int n, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {   int Inf=1e9;
        if(m==0 && n==0)
        return grid[m][n];
        if(m<0 || n<0)
        return Inf;
        if(dp[m][n]!=-1)
        return dp[m][n];
        int up=grid[m][n]+minSum(m-1,n, grid, dp);
        int left=grid[m][n]+minSum(m, n-1, grid, dp);
        return dp[m][n]=min(up, left);

    }
public:
    int minPathSum(vector<vector<int>>& grid) {
         int m=grid.size();
         int n=grid[0].size();
         vector<vector<int>> dp(m, vector<int>(n,-1));
         int ans=minSum(m-1,n-1, grid, dp);
         return ans;
         
    }
};
