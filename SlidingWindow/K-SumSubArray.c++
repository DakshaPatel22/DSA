class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) 
    {
        int ans=(lessThanGoal( nums,goal)-lessThanGoal( nums, goal-1));
        return ans;
        
    }
    int lessThanGoal(vector<int>& nums, int goal)
    {
        if(goal <0)
        return 0;
        int r=0,l=0,co=0,sum=0;
        while(r<nums.size())
        {
                sum=sum+nums[r];
         while(sum > goal)
         {
            sum=sum-nums[l];
            l++;
         }   
         co=co+r-l+1;
         r++;
            
        }
        return co;
        
    }
    

};