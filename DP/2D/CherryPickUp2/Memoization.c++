class Solution {
    public:
    int helper(int r, int c, vector<vector<int>> & grid, int i, int j1, int j2, vector<vector<vector<int>>> &dp)
    {
        if(j1>=c || j1<0 || j2>=c || j2<0)
        return -1e9;
        if(i==r-1)
        {
            if(j1==j2)
            return grid[i][j1];
            else
            return grid[i][j1]+grid[i][j2];
        }
        if(dp[i][j1][j2]!=-1)
            return dp[i][j1][j2];
        int maxi=-1e9;
        for(  int dj1=-1; dj1<=1;dj1++)
        {
            for( int dj2=-1; dj2<=1;dj2++)
            {
                if(j1==j2) maxi=max(maxi, grid[i][j1]+helper(r,c,grid, i+1, j1+dj1, j2+dj2, dp));
                else
                  maxi= max(maxi,grid[i][j1]+grid[i][j2]+helper(r,c,grid, i+1, j1+dj1, j2+dj2, dp));
            }
        }
        return dp[i][j1][j2]=maxi;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) 
    {   
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
        int ans= helper(r,c, grid, 0, 0, c-1, dp);
        return ans;

    }
};
