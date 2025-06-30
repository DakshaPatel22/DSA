class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
    queue<pair<int, pair<int,int> >> q;
    int dr[] = {-1, 0, 1, 0};
     int dc[]={0,1,0,-1};
    int n=grid.size();
 
    vector<vector<int>>da(n,vector<int>(n, 1e9));
    da[0][0]=0;
    q.push({0,{0,0}});
    while(!q.empty())
    {
        auto it=q.front();
        int dis=it.first;
        int row=it.second.first;
        int col=it.second.second;
        for(int i=0;i<4;i++)
        {
            int nr=row+dr[i];
            int nc=col+dc[i];
     if(nr>=0 && nr<n && nc >=0 && nc <n && grid[nr][nc]==1 && da[nr][nc]> dis+1){
            da[nr][nc]=1+dis;
            if(nr==n-1 && nc == n-1)
            return dis+1;
            q.push({da[nr][nc], { nr, nc}});
     }
        }
    }
    return -1;
    }
};