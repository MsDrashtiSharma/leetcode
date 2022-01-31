class Solution {
public:
         int dfs(vector<vector<int>>& grid,int i,int j,vector<vector<bool>>&vis )
        {  // int dx[4]={0,1,0,-1};
           //int dy[4]={1,0,-1,0};
                if(i<0||j<0||i>=grid.size()||j>=grid[0].size()||grid[i][j]==0)
                        return 1;
                if(vis[i][j])
                        return 0;
                vis[i][j]=true;
                return dfs(grid,i-1,j,vis)+ dfs(grid,i+1,j,vis)+ dfs(grid,i,j-1,vis)+ dfs(grid,i,j+1,vis);
        }
    int islandPerimeter(vector<vector<int>>& grid) {
        int m=grid.size();
            int n=grid[0].size();
            vector<vector<bool>>vis(m,vector<bool>(n,false));
            for(int i=0;i<m;++i)
            {
                    for(int j=0;j<n;++j)
                    {
                            if(grid[i][j]==1)
                                    return dfs(grid,i,j,vis);
                    }
            }
            return -1;
            
    }
       
};