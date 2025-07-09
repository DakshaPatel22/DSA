class Solution {
    public:
    bool helper(int n, int target, vector<int> &a )
    {
        if(target==0)
        return true;
        if(n==0)
        return ( a[n]==target);
        bool dont=helper(n-1, target, a);
        bool take=false;
        if(target>=a[n])
        take=helper(n-1, target-a[n], a);
        return (take|| dont);
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum=sum +nums[i];
        }
        
        bool ans=(sum%2==0)?helper(nums.size()-1, sum/2, nums): false;
        return ans;
    }
};
