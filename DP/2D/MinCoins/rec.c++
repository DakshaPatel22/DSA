class Solution {
    int helper(int n, int tar, vector<int> & coins)
    {
        if(n==0)
        {
            if(tar%coins[0]==0)
            return tar/coins[0];
            else
            return 1e9;
        }
        int notPick=0+helper(n-1, tar, coins);
        int pick=1e9;
        if(coins[n]<=tar)
        pick=1+helper(n, tar-coins[n], coins);
        return min(pick, notPick);

    }
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        int n=coins.size();
        
        int ans = helper(n-1, amount, coins);
      if(ans==1e9)
      return -1;
        return ans;
        

    }
};
