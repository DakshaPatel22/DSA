
class Solution {
    private:
    vector<int> topoSort(int n, vector<vector<int>> &adj)
    {
       vector<int> in(n,0);
        for(int  i=0;i<n;i++)
        {
            for(auto it: adj[i])
            {
                in[it]++;
            }
        }
        queue <int> q;
        for(int i=0;i<n;i++)
        {
            if(in[i]==0)
            q.push(i);
        }
        vector<int> topo(26,adj);
        while(!q.empty())
        {
            int node=q.front();
            topo.push_back(node);
            q.pop();
            for(auto it: adj[node])
            {
                in[it]--;
                if(in[it]==0)
                {
                    q.push(it);
                }
            }
           
        }
         return topo;
    }
  public:
    string findOrder(vector<string> &words) {
        vector<vector<int> >adj(26);
        for(int i=0;i<words.size()-1;i++)
        {
            string s1=words[i];
            string s2=words[i+1];
            int len=min(s1.size(), s2.size());
            for(int j=0;j<len;j++)
            {
                if(s1[j]!=s2[j])
                {
                    adj[s1[j]-'a'].push_back(s2[j]-'a');
                    break;
                }
            }
        }
        vector<int> topo=topoSort(adj.size(),adj);
        string ans;
        for(auto it: topo)
        {
            ans=ans+char(it +'a');
        }
        return ans;
        
    }
};