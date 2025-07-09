class Solution {
    public:
    bool helper(int n, int target, vector<int> &a, vector<vector<int>> &dp)
    {
        if(target==0)
        return true;
        if(n==0)
        return ( a[n]==target);
        if(dp[n][target]!=-1)
        return dp[n][target];
        bool dont=helper(n-1, target, a, dp);
        bool take=false;
        if(target>=a[n])
        take=helper(n-1, target-a[n], a,dp);
        return dp[n][target]=(take|| dont);
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum=sum +nums[i];
        } int  n=nums.size();
        int target=sum/2;
        if(sum%2!=0) return false;
        // vector<vector<int>>dp(nums.size(), vector<int>(sum/2 + 1, -1));
        // bool ans=(sum%2==0)?helper(nums.size()-1, sum/2, nums, dp): false;
        vector<vector<bool>>dp(n, vector<bool>(target + 1, false));
       
        for(int i=0;i<n;i++)
        {
            dp[i][0]=true;
        }
        if (nums[0] <= target)
        dp[0][nums[0]]=true;
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<=target;j++)
            {
              bool dont=dp[i-1][j];
              bool take=false;
                if(j>=nums[i])
                   take=dp[i-1][j-nums[i]];
              dp[i][j]=take || dont;
            }
        }


        return dp[n-1][target];
    }
};
