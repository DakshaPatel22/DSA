class Solution {
    // public :
    // int helper(int n, int w, vector<int> & val, vector<int> & wt, vector<vector<int>> &dp)
    // {
    //     if(n==0)
    //     {
    //         if(wt[0]<=w)
    //         return val[0];
    //         else
    //         return 0;
    //     }
    //     if(dp[n][w]!=-1)
    //         return dp[n][w];
    //     int notpick =0+ helper(n-1, w, val, wt, dp);
    //     int  pick=0;
    //     if(wt[n]<=w)
    //         pick =val[n]+helper(n-1, w-wt[n], val, wt, dp);
    //     return dp[n][w]=max(pick, notpick);
    // }
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n=wt.size();
        vector<vector<int>> dp(n, vector<int>(W+1, 0));
        for(int i=wt[0]; i<=W;i++)
        {
            dp[0][i]=val[0];
        }
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=W;j++)
            {
                int notpick=0+dp[i-1][j];
                int pick=-1e9;
                if(wt[i]<=j)
                pick=val[i]+dp[i-1][j-wt[i]];
                dp[i][j]=max(pick, notpick);
            }
        }
        return dp[n-1][W];
        
    }
};
