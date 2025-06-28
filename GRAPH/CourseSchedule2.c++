class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
   
    vector<vector<int>> adj(numCourses);
    for(auto it:prerequisites)
    {
        adj[it[1]].push_back(it[0]);

    }
    vector<int> id(numCourses,0);
    for(int i=0;i<numCourses;i++)
    {
        for(auto it: adj[i])
        {
            id[it]++;
        }
    }
    queue<int> q;
    for(int i=0;i<numCourses;i++)
    {
        
            if(id[i]==0)
            q.push(i);
        
    }
    vector<int> topo;
    while( !q.empty())
    {
        int node=q.front();
        topo.push_back(node);
        q.pop();
        for(auto it:adj[node])
        { id[it]--;
            if(id[it]==0){
                q.push(it);
            }

        }
    }
    if(topo.size()==numCourses)
    {
        return topo;

    }
    else return {};
        
    }
};
