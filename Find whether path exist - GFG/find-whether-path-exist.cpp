// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    void solve(vector<vector<int>>&grid,vector<vector<bool>>&visited,int a, int b)
    {
        int n=grid.size();
        if(a<0 || a>=n || b<0 || b>=n || visited[a][b]==true || grid[a][b]==0)
        return;
        visited[a][b]=true;
        solve(grid,visited,a+1,b);
        solve(grid,visited,a-1,b);
        solve(grid,visited,a,b+1);
        solve(grid,visited,a,b-1);
    }
    bool is_Possible(vector<vector<int>>& grid) 
    {
        //code here
        int n=grid.size();
        int m=grid[0].size();
        int a,b,tx,ty;
        vector<vector<bool>>visited(n,vector<bool>(n,false));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {a=i;b=j;}
                if(grid[i][j]==2)
               { tx=i;ty=j;}
                
            }
        }
        solve(grid,visited,a,b);
        return visited[tx][ty];
        
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