class Solution {
    // public:
    // int mini(int m, int n, vector<vector<int>>&dp, vector<vector<int>>& triangle)
    // {int size=triangle.size();
    //     if(m==size-1)
    //     return triangle[m][n];

    //     if(dp[m][n]!=-1)return dp[m][n];
    //     int d=triangle[m][n]+mini(m+1, n, dp, triangle);
    //     int diag=triangle[m][n]+mini(m+1,n+1, dp, triangle);
    //     return dp[m][n]=min(d,diag);
    // }
public:
    int minimumTotal(vector<vector<int>>& triangle) 
    { int n=triangle.size();
        vector<vector<int>> dp(n,vector<int>(n , -0));
        for(int j=0;j<n;j++)
        dp[n-1][j]=triangle[n-1][j];
       for(int i=n-2;i>=0;i--)
       {
        for(int j=i;j>=0;j--)
        {
             int d=triangle[i][j]+dp[i+1][j];
        int diag=triangle[i][j]+dp[i+1][j+1];
        dp[i][j]=min(d, diag);
        }
       }
        return dp[0][0];
    }
};
