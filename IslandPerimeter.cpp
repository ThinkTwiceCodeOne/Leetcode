class Solution {
public:
    int deltaX[4]={0,0,1,-1};
    int deltaY[4]={1,-1,0,0};
    int ans=0;
    bool isValid(int x,int y,vector<vector<int>>& grid,int n,int m)
    {
        if((x>=0 && y>=0 && x<n && y<m) && grid[x][y]==1) return true;
        return false;
    }
    void dfs(int x,int y,vector<vector<int>>& vis,vector<vector<int>>& grid,int n,int m)
    {
        vis[x][y]=1;
        for(int i=0;i<4;i++)
        {
            int newX=x+deltaX[i];
            int newY=y+deltaY[i];
            if(isValid(newX,newY,grid,n,m)==false) 
            {
                ans++;
            }
        }
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]==1 && vis[i][j]==0)
                {
                    dfs(i,j,vis,grid,n,m);
                }
            }
        }
        return ans;
        
    }
};
