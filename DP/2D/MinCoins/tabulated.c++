class Solution {
    int helper(int n, int tar, vector<int> & coins, vector<vector<int>> &dp)
    {
        if(n==0)
        {
            if(tar%coins[0]==0)
            return tar/coins[0];
            else
            return 1e9;
        }
        if(dp[n][tar]!=-1)
        return dp[n][tar];
        int notPick=0+helper(n-1, tar, coins, dp);
        int pick=1e9;
        if(coins[n]<=tar)
        pick=1+helper(n, tar-coins[n], coins, dp);
        return dp[n][tar]=min(pick, notPick);

    }
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        int n=coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, 0));
        int ans = helper(n-1, amount, coins, dp);
        for(int tar=0;tar<=amount; tar++)
        {
            if(tar%coins[0]==0)
            dp[0][tar]=tar/coins[0];
            else
            dp[0][tar]=1e9;
        } 
        for(int in=1;in<n;in++)
        {
            for(int tp=0;tp<=amount;tp++)
            {
                int notPick=0+dp[in-1][tp];
                int pick=1e9;
                if(coins[in]<=tp)
                pick=1+dp[in][tp-coins[in]];
                dp[in][tp]= min(pick, notPick);
            }
        }
      if(dp[n-1][amount]==1e9)
      return -1;
        return dp[n-1][amount];
        

    }
};
