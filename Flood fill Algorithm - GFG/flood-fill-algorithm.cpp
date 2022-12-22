//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void dfs(int row,int col,vector<vector<int>>& image,int newColor,int delrow[],int delcol[],vector<vector<int>>&ans,int inicolor)
    {
        ans[row][col]=newColor;
        int n=image.size();
        int m=image[0].size();
        for(int i=0;i<4;i++)
        {
            int r=row+delrow[i];
            int c=col+delcol[i];
            if(r>=0&&r<n&&c>=0&&c<m&&image[r][c]==inicolor&&ans[r][c]!=newColor)
            {
                dfs(r,c,image,newColor,delrow,delcol,ans,inicolor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int inicolor=image[sr][sc];
        vector<vector<int>>ans=image;
        int delrow[]={-1,0,+1,0};
        int delcol[]={0,+1,0,-1};
        dfs(sr,sc,image,newColor,delrow,delcol,ans,inicolor);
        return ans;
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends