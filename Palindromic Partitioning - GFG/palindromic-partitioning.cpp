//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
int ispalindrome(int i,int j,string s)
{
    while(i<j)
    {
        if(s[i]!=s[j])return false;
        i++;
        j--;
    }
    return true;
}
int f(int i,int n, string s,vector<int>&dp)
{
    if(i==n)return 0;
    int mincost=INT_MAX;
    if(dp[i]!=-1)return dp[i];
    for(int j=i;j<n;j++)
    {
        if(ispalindrome(i,j,s))
        {
           int cost=1+f(j+1,n,s,dp);
            mincost=min(cost,mincost);
        }
    }
    return dp[i]=mincost;
}
    int palindromicPartition(string str)
    {
        // code here
        int n=str.size();
        vector<int>dp(n+1,0);
        
        for(int i=n;i>=0;i--)
        {
            if(i==n)continue;
            int mincost=INT_MAX;
            
            for(int j=i;j<n;j++)
            {
                if(ispalindrome(i,j,str))
                {
                   int cost=1+dp[j+1];
                    mincost=min(cost,mincost);
                }
            }
            dp[i]=mincost;
            
        }
        return dp[0]-1;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends