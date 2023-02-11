//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
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
    int longestPalinSubseq(string A) {
        //code here
        string B=A;
        reverse(A.begin(),A.end());
        int x=A.size();
        int y=B.size();
        return lcs(x,y,A,B);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends