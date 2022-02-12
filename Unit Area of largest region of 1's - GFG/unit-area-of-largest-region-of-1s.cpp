// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
      int dfs(vector<vector<int>>&grid,int i,int j,int m,int n){
       if(i<0||j<0||i>=m||j>=n||grid[i][j]!=1){
           return 0;
       }
       int sum=0;
       sum++;
       grid[i][j]=0;
       sum+=dfs(grid,i-1,j,m,n);
       sum+=dfs(grid,i-1,j+1,m,n);
       sum+=dfs(grid,i,j+1,m,n);
       sum+=dfs(grid,i+1,j+1,m,n);
       sum+=dfs(grid,i+1,j,m,n);
       sum+=dfs(grid,i+1,j-1,m,n);
       sum+=dfs(grid,i,j-1,m,n);
       sum+=dfs(grid,i-1,j-1,m,n);
       return sum;
   }
    //Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
       int ans=INT_MIN;
       int m=grid.size();
       int n=grid[0].size();
       for(int i=0;i<m;i++){
           for(int j=0;j<n;j++){
               if(grid[i][j]==1){
                  int temp=dfs(grid,i,j,m,n);
                  ans=max(ans,temp);
               }
           }
       }
       return ans;
     
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends