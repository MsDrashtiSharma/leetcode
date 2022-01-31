// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the number of 'X' total shapes.
    void dfs(int i,int j,vector<vector<char>>& grid)
    {  // int dx[4]={-1,1,0,0};
      //int dy[4]={0,0,-1,1};
     
        if (i<0||i>=grid.size()||j<0||j>=grid[0].size()||grid[i][j]=='O')
        {return ;}
        grid[i][j]='O';
        //v[i][j]='O';
       dfs(i+1,j,grid);
       dfs(i-1,j,grid);
       dfs(i,j+1,grid);
       dfs(i,j-1,grid);
        
    }
    int xShape(vector<vector<char>>& grid) 
    {
        // Code here
        int count=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='X')
                {
                    dfs(i,j,grid);
                    count++;
                }
            }
        }
        return count;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.xShape(grid);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends