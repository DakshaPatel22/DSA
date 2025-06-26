class Solution {
    private:
    bool dfs(int node, int col, vector<int> &colour, vector<vector<int>> & g)
    {
        colour[node]=col;
        for(auto it: g[node])
        {
            if(colour[it]==-1)
            {
                if(dfs(it, !col, colour, g)==false)
                return false;
            }
            else if(colour[it]==col)
            {
                return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        int v=graph.size();
       vector<int> colour(v,-1);
        for(int i=0;i<v;i++)
        {
            if(colour[i]==-1)
            {
                if(dfs(i,0,colour,graph)==false)
                return false;
            }
        }
        return true;
    }
};