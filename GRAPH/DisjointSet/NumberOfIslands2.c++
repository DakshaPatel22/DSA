class DisjointSet {
    public:
vector<int> rank, parent, size;
DisjointSet(int n) {
        rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
int findPar(int node) 
{
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
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        DisjointSet ds(n*n);
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        for( int i=0;i<n;i++)// nodes setting in disjoint set
        {
            for(int j=0;j<n;j++)
            {

             if(grid[i][j]==0)
             continue;
             for(int a=0;a<4;a++)
             {
                int ni=i+dr[a];
                int nj=j+dc[a];
                if(ni>=0 &&  ni<n && nj>=0 && nj<n && grid[ni][nj]==1)
                { int curNode=i*n + j;
                int adjNode=ni*n +nj;
                    ds.unionBySize(curNode, adjNode);
                }
             }

            }
        }
       
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            { 
                if(grid[i][j]==0)
                {  set<int> comp; 
                    for(int a=0;a<4;a++)
                    {
                    int ni=i+dr[a];
                    int nj=j+dc[a];
                    if(ni>=0 && nj>=0 && ni<n && nj<n && grid[ni][nj]==1)
                    { int node=ni*n + nj;
                        int par=ds.findPar(node);
                 comp.insert(par);
                    }
                    }
                    int compsize=0;
                    for(auto it:comp)
                    {
                        compsize=compsize+ds.size[it];
                    }
                    ans=max(ans, compsize+1);

                }
            }
        }
for(int i = 0; i < n*n; i++) {
    ans = max(ans, ds.size[ds.findPar(i)]);
}
return ans;
    }
};