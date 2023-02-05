//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int f(int i,int j,vector<vector<int>>&dp,string s,string t)
  {
      if(i<0)
      return j+1;
      if(j<0)
      return i+1;
      if(dp[i][j]!=-1)
      return dp[i][j];
      if(s[i]==t[j])return dp[i][j]=0+f(i-1,j-1,dp,s,t);
      return dp[i][j]=1+min(f(i,j-1,dp,s,t),min(f(i-1,j-1,dp,s,t),f(i-1,j,dp,s,t)));
  }
    int editDistance(string s, string t) {
        // Code here
        int n=s.size();
        int m=t.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(n-1,m-1,dp,s,t);
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends