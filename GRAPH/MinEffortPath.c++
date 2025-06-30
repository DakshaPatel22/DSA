class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) 
    {
        priority_queue< pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>dis(n, vector<int>(m, 1e9));
        int dr[4]={-1,0,1,0};
        int dc[4]={0,1,0,-1};
        dis[0][0]=0;
     pq.push({0,{0,0}});
     while(!pq.empty())
     {
        auto it=pq.top();
        pq.pop();
        int dif=it.first;
        int r=it.second.first;
        int c= it.second.second;
        if(r==n-1 && c==m-1)
        {
            return dif;
        }
        for(int i=0;i<4;i++)
        {
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m)
            {
                int NewEffort=max(abs(heights[r][c]-heights[nr][nc]), dif);
                if(NewEffort<dis[nr][nc])
                {
                    dis[nr][nc]=NewEffort;
                    pq.push({NewEffort, { nr, nc}});
                }
            }
        }
     }
        return 0;
    }
};