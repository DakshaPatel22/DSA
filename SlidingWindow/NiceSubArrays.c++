class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
         int ans=(lessThanGoal( nums,k)-lessThanGoal( nums, k-1));
        return ans;
    }
    int lessThanGoal(vector<int>& nums, int goal)
    {
        if(goal <0)
        return 0;
        int r=0,l=0,co=0,sum=0;
        while(r<nums.size())
        {
                sum=sum+(nums[r]%2);
         while(sum > goal)
         {
            sum=sum-(nums[l]%2);
            l++;
         }   
         co=co+r-l+1;
         r++;
            
        }
        return co;
        
    }
};