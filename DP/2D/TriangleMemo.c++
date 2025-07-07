class Solution {
    public:
    int mini(int m, int n, vector<vector<int>>&dp, vector<vector<int>>& triangle)
    {int size=triangle.size();
        if(m==size-1)
        return triangle[m][n];

        if(dp[m][n]!=-1)return dp[m][n];
        int d=triangle[m][n]+mini(m+1, n, dp, triangle);
        int diag=triangle[m][n]+mini(m+1,n+1, dp, triangle);
        return dp[m][n]=min(d,diag);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) 
    { int n=triangle.size();
        vector<vector<int>> dp(n,vector<int>(n , -1));
        int ans=mini(0,0, dp, triangle);
        return ans;
    }
};
