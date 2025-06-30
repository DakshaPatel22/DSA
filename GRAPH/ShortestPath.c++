class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {int n=grid.size();
    queue<pair<int, pair<int,int> >> q;
  int dr[8] = {-1, -1,  0, 1, 1, 1,  0, -1};
  int dc[8] = { 0,  1,  1, 1, 0, -1, -1, -1};
  if(grid[0][0] == 1 || grid[n-1][n-1] == 1)
  return -1;
        if(n == 1) 
        return (grid[0][0] == 0) ? 1 : -1;
    vector<vector<int>>da(n,vector<int>(n, 1e9));
    da[0][0]=0;
    q.push({0,{0,0}});
    while(!q.empty())
    {
        auto it=q.front();
        q.pop();
        int dis=it.first;
        int row=it.second.first;
        int col=it.second.second;
        for(int i=0;i<8;i++)
        {
            int nr=row+dr[i];
            int nc=col+dc[i];
     if(nr>=0 && nr<n && nc >=0 && nc <n && grid[nr][nc]==0 && da[nr][nc]> dis+1)
     {
            da[nr][nc]=1+dis;
            if(nr==n-1 && nc == n-1)
            return da[nr][nc]+1;
            q.push({1+dis, { nr, nc}});
     }
        }
    }
    return -1;
    }
};