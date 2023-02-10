//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int f(int i,int j,string s1,string s2,vector<vector<int>>&dp)
    {
        if(i<0||j<0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s1[i]==s2[j])return dp[i][j]=1+f(i-1,j-1,s1,s2,dp);
        return dp[i][j]=max(f(i-1,j,s1,s2,dp),f(i,j-1,s1,s2,dp));
    }
    int longestCommonSubstr (string s1, string s2, int x, int y)
    {
        vector<vector<int>>dp(x+1,vector<int>(y+1,0));
        for(int i=0;i<=x;i++)
        dp[i][0]=0;
        for(int j=0;j<=y;j++)
        dp[0][j]=0;
        int ans=0;
        for(int i=1;i<=x;i++)
        {
            for(int j=1;j<=y;j++)
            {
            //   if(dp[i][j]!=-1)dp[i][j];
                if(s1[i-1]==s2[j-1])
                {
                   dp[i][j]=1+dp[i-1][j-1];
                  ans=max(ans,dp[i][j]);             }
               
                else
                dp[i][j]=0  ;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends