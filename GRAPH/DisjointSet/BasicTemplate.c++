#include <bits/stdtr1c++.h>
using namespace std;
class disjoinse
{
vector<int>rank, parent;
public:
   DisjoinSet(int n)
   {
    rank.resize(n+1, 0);
    parent.resize(n+1);
    for(int i=0i<=n;i++)
    {
        parent[i]=i;
    }
   }
   int findUparent(int node)
   {
    if(node==parent[node])
    {
        return node;
    }
    return parent[node]=findUparent(parent[node]);
   }
   void unionByRank(int u, int v)
   {
    int ulp_u=findUparent(u);
    int ulp_v=findUparent(v);
    if(ulp_u==ulp_v)
    return;
    else if(rank[ulp_u]< rank[ulp_v])
    {
        parent[ulp_u]=ulp_v;
    }
    else if(rank[ulp_v]< rank[ulp_u])
    {
        parent[ulp_v]=ulp_u;
        rank[ulp_u]++;
    }
   }
}