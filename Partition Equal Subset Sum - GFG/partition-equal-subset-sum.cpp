//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
int solve(int n,int arr[],int k,vector<vector<int>>&dp)
{
    for(int i=0;i<n;i++)
    dp[i][0]=true;
    dp[0][arr[0]]=true;
    // if(dp[i][target]!=-1)
    // return dp[i][target];
    for(int i=1;i<n;i++)
    {
        for(int target=1;target<=k;target++)
        {
           bool nottake=dp[i-1][target];
            bool take=false;
            if(arr[i]<=target)
            take=dp[i-1][target-arr[i]]; 
            dp[i][target]=take||nottake;
        }
    }
   
    return dp[n-1][k];
}
    int equalPartition(int n, int arr[])
    {
        // code here
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
        }
        if(sum%2)return false;
        int target=sum/2;
        vector<vector<int>>dp(n,vector<int>(target+1,0));
        return solve(n,arr,target,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends