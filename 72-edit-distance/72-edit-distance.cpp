class Solution {
public:
  /*  int f(int i, int j,vector<vector<int>>&dp,string &s1, string &s2)
    {
        if(i<0)
            return j+1;
        if(j<0) 
            return i+1;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(s1[i]==s2[j])
            return dp[i][j]=0+f(i-1,j-1,dp,s1,s2);
            return dp[i][j]=1+min(f(i-1,j,dp,s1,s2), min(f(i,j-1,dp,s1,s2),f(i-1,j-1,dp,s1,s2)));
                                    //insert            // delete               //replace
    }
    }    
    int minDistance(string s1, string s2) {
        int n=s1.size();
        int  m=s2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(n-1,m-1,dp,s1,s2);
    }*/
    
  /*  int minDistance(string s1, string s2) {
        int n=s1.size();
        int  m=s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int j=0;j<=m;j++)  //we shift the index by +1 so the condition is if(i==0)return j;
            dp[0][j]=j;
        for(int i=0;i<=n;i++)
            dp[i][0]=i;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s1[i-1]==s2[j-1])
                    dp[i][j]=dp[i-1][j-1];
                else
                    dp[i][j]=1+min(dp[i-1][j], min(dp[i][j-1],dp[i-1][j-1]));
            }
        }
        return dp[n][m];*/
     int minDistance(string s1, string s2) {
        int n=s1.size();
        int  m=s2.size();
       vector<int>prev(m+1,0),curr(m+1,0);
         for(int j=0;j<=m;j++)
            prev[j]=j;
       
       
        for(int i=1;i<=n;i++)
        {  curr[0]=i;
            for(int j=1;j<=m;j++)
            {
                if(s1[i-1]==s2[j-1])
                    curr[j]=prev[j-1];
                else
                    curr[j]=1+min(prev[j], min(curr[j-1],prev[j-1]));
            }
            prev=curr;
        }
        return prev[m];
     }
};