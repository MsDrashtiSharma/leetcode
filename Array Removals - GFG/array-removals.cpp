//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
  
    int f(vector<int>&arr,int i,int j,int k,vector<vector<int>>&dp)
    {   
        if(i>=j)
        return 0;
        if(arr[j]-arr[i]<=k)
        return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        return dp[i][j]=1+min(f(arr,i+1,j,k,dp),f(arr,i,j-1,k,dp));
    }
    int removals(vector<int>& arr, int k){
        //Code here
        int n=arr.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        sort(arr.begin(),arr.end());
        if(n==1)return 0;
        else
        return f(arr,0,n-1,k,dp);
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        Solution ob;
        int ans = ob.removals(arr,k);
        
        cout<<ans<<endl;
    }
}



// } Driver Code Ends