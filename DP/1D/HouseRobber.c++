class Solution {
    int maxMon( vector<int> &nums)
    {
        int ind=nums.size();
        int prev=nums[0];
        int prev2=0;
        for(int i=1;i<ind;i++)
    {
        int take=nums[i];
        if(i>1)
           take=take+prev2;
        int leave=0+prev;
        int curr=max(take,leave);
        prev2=prev;
        prev=curr;
}

return prev;

    }
public:
    int rob(vector<int>& nums) 
    {
      
        return maxMon( nums);
    }
};
