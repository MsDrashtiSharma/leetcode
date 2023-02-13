//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
class Solution{
    public:
    long long solve(int arr[], vector<vector<int>>&dp,int i,int j)
    {
        if(i>j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int x=arr[i]+min(solve(arr,dp,i+2,j),solve(arr,dp,i+1,j-1));
        int y=arr[j]+min(solve(arr,dp,i+1,j-1),solve(arr,dp,i,j-2));
        return dp[i][j]=max(x,y);
    }
    long long maximumAmount(int arr[], int n){
        // Your code here
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(arr,dp,0,n-1);
        
    }
};

//{ Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(a,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends