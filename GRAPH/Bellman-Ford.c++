class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<int> dist(V, 1e8);
        dist[src]=0;
        for(int i=0;i<V-1;i++)
        {
            for(auto it: edges)
            {
                int u= it[0];
                int v=it[1];
                int edw=it[2];
                if(dist[u]!=1e8 && dist[u]+edw < dist[v])
                {
                    dist[v]=dist[u]+edw;
                }
            }
        }
        for(auto it:edges)
        {
            int u=it[0];
            int v=it[1];
            int ew=it[2];
            if(dist[u]!=1e8 && dist[u]+ew<dist[v])
            return {
                -1
            };
        }
        return dist;
        
    }
};
