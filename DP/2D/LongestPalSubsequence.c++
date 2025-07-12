class Solution {
    int helper(string s1, string s2)
    {
      int n1=s1.size();
      int n2=s2.size();
      vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
      for( int i=0;i<=n1; i++)
      {
        dp[0][i]=0;
      }
      for( int i=0;i<=n2;i++)
      {
        dp[i][0]=0;
      }
      for( int i=1;i<=n1;i++)
      {
        for( int j=1;j<=n2;j++)
        {
            if(s1[i-1]==s2[j-1])
            dp[i][j]=1+dp[i-1][j-1];
            else
            dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
        }
      }
      return dp[n1][n2];
    }

public:
    int longestPalindromeSubseq(string s) 
    { 
        string revs=s;
        reverse(revs.begin(), revs.end());
    int ans=helper(s, revs);
    return ans;
    }
};
