//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int f(int i,int j,string s1,string s2,vector<vector<int>>&dp)
    {
        if(i<0||j<0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s1[i]==s2[j])return dp[i][j]=1+f(i-1,j-1,s1,s2,dp);
        return dp[i][j]=max(f(i-1,j,s1,s2,dp),f(i,j-1,s1,s2,dp));
    }
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        // int n=s1.size();
        // int m=s2.size();
        vector<vector<int>>dp(x+1,vector<int>(y+1,0));
        vector<int>prev(y+1,0),curr(y+1,0);
        // for(int i=0;i<=x;i++)
        // dp[i][0]=0;
        for(int j=0;j<=y;j++)
        prev[j]=0;
        for(int i=1;i<=x;i++)
        {
            for(int j=1;j<=y;j++)
            {
            //   if(dp[i][j]!=-1)dp[i][j];
                if(s1[i-1]==s2[j-1])
                curr[j]=1+prev[j-1];
                else
                curr[j]=max(prev[j],curr[j-1]);  
            }
            prev=curr;
        }
        return prev[y];
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends