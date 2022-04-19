class Solution {
public:
    int f(int ind,int buy,vector<int>& prices,int n, vector<vector<vector<int>>>&dp,int cap)
    {
        if(ind==n||cap==0)
            return 0;
        int profit=0;
        if(dp[ind][buy][cap]!=-1)
            return dp[ind][buy][cap];
        if(buy==1)
        {
            profit=max((-prices[ind]+f(ind+1,0,prices,n,dp,cap)),(0+f(ind+1,1,prices,n,dp,cap)));
        }
       else
       {
               profit=max((prices[ind]+f(ind+1,1,prices,n,dp,cap-1)),(0+f(ind+1,0,prices,n,dp,cap)));            
       }
    
                          
           return dp[ind][buy][cap]=profit;               
    }
    int maxProfit(vector<int>& prices) {
       int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return f(0,1,prices,n,dp,2);
    }
};