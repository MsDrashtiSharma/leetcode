class Solution {
public:
    int ispalindrome(int i,int j,string &s)
    {
        while(i<j)
        {
            if(s[i]!=s[j])return false;
            i++;
            j--;
        }
        return true;
    }
    int f(int i,int n,string &s, vector<int>&dp)
    {
        if(i==n)return 0;
        int minicost=INT_MAX;
        if(dp[i]!=-1)
            return dp[i];
        for(int j=i;j<n;j++)
        {
            if(ispalindrome(i,j,s))
            {
                int cost=1+f(j+1,n,s,dp);
                minicost=min(cost,minicost);
            }
            
        }
        return dp[i]=minicost;
    }
    int minCut(string s) {
        int n=s.size();
        vector<int>dp(n+1,0);
        for(int i=n;i>=0;i--)
        {
             if(i==n)continue;;
            int minicost=INT_MAX;
           
            for(int j=i;j<n;j++)
            {
            if(ispalindrome(i,j,s))
            {
                int cost=1+dp[j+1];
                minicost=min(cost,minicost);
            }
            }
                dp[i]=minicost;
        
        }
        return dp[0]-1;
    }
};