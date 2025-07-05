class DisjointSet {
    vector<int> rank, parent, size;

public:
    DisjointSet(int n) {
        rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findPar(int node) {
        if(node == parent[node])
            return node;
        return parent[node] = findPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findPar(u);
        int ulp_v = findPar(v);
        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    
void unionBySize(int u, int v) {
    int ulp_u = findPar(u);
    int ulp_v = findPar(v);
    if(ulp_u == ulp_v) return;
    if(size[ulp_u] < size[ulp_v]) {
        parent[ulp_u] = ulp_v;
        size[ulp_v] += size[ulp_u];
    }
    else {
        parent[ulp_v] = ulp_u;
        size[ulp_u] += size[ulp_v];
    }
}
};
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        int n=grid.size();
    vector<int> vis(n*n, 0);
    vector<pair<int, pair<int,int>>> data;
    DisjointSet ds(n*n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            data.push_back({grid[i][j],{i,j}});
        }
    }
    sort(data.begin(),data.end());
    for(auto it: data)
    {
        int el=it.first;
        int row=it.second.first;
        int col=it.second.second;
        int node= row*n+col;
        vis[node]=1;
        for(int i=0;i<4;i++)
        {
            int nr=row+dr[i];
            int nc=col+dc[i];
            if(nr>=0 && nc>=0 && nr<n && nc< n)
            {
              int newNode=nr*n+nc;
              if(vis[newNode]==1)
              {
                ds.unionBySize(node, newNode);
              }
  
            }

            
        }
        int destNode=(n-1)*n + (n-1);
        if(ds.findPar(0)==ds.findPar(destNode))
        return el;
    }
    return -1;
    }
};
