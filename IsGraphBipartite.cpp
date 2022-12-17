class Solution {
public:
    int count=0;
    bool dfs(int node,int col,vector<int>& color,vector<vector<int>>& adj)
    {
        color[node]=col;
        for(auto i:adj[node])
        {
            if(color[i]==-1) 
            {
                if(dfs(i,!col,color,adj)==false) return false;
            }
            else if(color[i]==col) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        int m=graph[0].size();
        vector<int> adj[n];
        vector<int> color(n,-1);
        bool result=false;
        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
                if(dfs(i,0,color,graph)==false) return false;
            }
        }
        return true;
        
    }
};
