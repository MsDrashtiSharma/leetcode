//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int f(int i,int previ,int arr[],int n,vector<vector<int>>&dp)
	{
	    if(i==n)return 0;
	    if(dp[i][previ+1]!=-1)return dp[i][previ+1];
	    int len=f(i+1,previ,arr,n,dp);
	    if(previ==-1||arr[i]>arr[previ])
	    {
	        len=max(len,arr[i]+f(i+1,i,arr,n,dp));
	    }
	    return dp[i][previ+1]=len;
	}
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
	    return f(0,-1,arr,n,dp);
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends