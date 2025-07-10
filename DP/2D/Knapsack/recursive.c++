class Solution {
    public :
    int helper(int n, int w, vector<int> & val, vector<int> & wt)
    {
        if(n==0)
        {
            if(wt[0]<=w)
            return val[0];
            else
            return 0;
        }
        int notpick =0+ helper(n-1, w, val, wt);
        int  pick=0;
        if(wt[n]<=w)
            pick =val[n]+helper(n-1, w-wt[n], val, wt);
        return max(pick, notpick);
    }
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n=wt.size();
        int ans=helper(n, W, val, wt);
        return ans;
        
    }
};
