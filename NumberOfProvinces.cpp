class Solution {
public:
    void dfs(int node,vector<int> adj[],vector<int>& vis)
    {
        vis[node]=1;
        for(auto it:adj[node])
        {
            if(vis[it]==0) dfs(it,adj,vis);
        }
        
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> vis(n+1,0);
        vector<int> adj[n+1];
        for(int i=0;i<isConnected.size();i++)
        {
            for(int j=0;j<isConnected[i].size();j++)
            {
                if(isConnected[i][j]==1) 
                {
                    if(i==j) continue;
                    adj[i+1].push_back(j+1);
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(vis[i]==0)
            {
                ans++;
                dfs(i,adj,vis);
            }
        }
        return ans;
        
    }
};
