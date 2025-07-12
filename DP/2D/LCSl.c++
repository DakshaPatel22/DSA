class Solution {
    // int helper(int in1, int in2, string text1, string text2, vector<vector<int>> &dp)
    // {
    //     if(in1<0 || in2<0 )
    //     return 0;
    //     if(dp[in1][in2]!=-1)
    //     return dp[in1][in2];
    //     if(text1[in1]==text2[in2])
    //     return 1+helper(in1-1, in2-1, text1, text2, dp);
    //     return dp[in1][in2]=0+ max(helper(in1-1, in2, text1, text2, dp), helper(in1, in2-1, text1, text2, dp));
    // }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.size();
        int n2=text2.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
        for(int i=0;i<=n1;i++)
        {
            dp[i][0]=0;
        }
        for(int j=0;j<=n2;j++)
        {
            dp[0][j]=0;
        }
        for(int i=1;i<=n1;i++)
        {
            for(int j=1;j<=n2;j++)
            {
                if(text1[i-1]==text2[j-1])  dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }

       return dp[n1][n2];
    }
};
