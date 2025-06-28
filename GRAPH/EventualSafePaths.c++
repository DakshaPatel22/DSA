class Solution {
    private:
    bool dfs(int node, vector<int> &v,vector<int> &pv , vector<vector<int>> &gr, vector<int> &ch)
    {
        v[node]=1;
        pv[node]=1;
        for(auto it:gr[node])
        {
            if(!v[it])
            {
                if(dfs(it, v, pv, gr, ch))
                {
                    ch[node]=0;// if a cycle exists in the adjacent neighbours of a node, then that node cannot be a safe node, so unmark that
                    return true;
                }}
                else if(pv[it])
                {
                    ch[node]=0;
                    return true;
                }
              
            }
              ch[node]=1;
              pv[node]=0;
              return false;
        }
    
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> vis(graph.size(), 0);
        vector<int>check(graph.size(), 0);
        vector<int> pvis(graph.size(), 0);
        for( int i=0;i<graph.size();i++)
        {
            if(!vis[i])
            dfs(i,vis, pvis,graph, check);
        }
        vector<int> ans;
        for(int i=0;i<graph.size();i++)
        {
            if(check[i]==1)
            {
                ans.push_back(i);
            }
        }
        return ans;
        

        
    }
};