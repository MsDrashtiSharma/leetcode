// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    void checkpath(vector<vector<int>>& grid,  vector<vector<bool>> &vis,int x, int y )
    {
        int n=grid.size();
        if(x<0|| x>=n || y<0 || y>=n || vis[x][y]==true || grid[x][y]==0)
           return;
        vis[x][y]=true;
        checkpath(grid, vis, x+1, y); //down
        checkpath(grid, vis, x-1, y); //up
        checkpath(grid, vis, x, y+1); // left
        checkpath(grid, vis, x, y-1); // right
    }
    
bool is_Possible(vector<vector<int>>& grid) 
    {
        int n=grid.size(), m=grid.size(), x, y, tx, ty;
        
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]==1){
                    x=i, y=j;
                }
                if(grid[i][j]==2){
                    tx=i, ty=j;
                }
            }
        }
        checkpath(grid, vis, x, y);
        return vis[tx][ty];
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}  // } Driver Code Ends