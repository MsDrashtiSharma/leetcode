class Solution {
public:
    int f(vector<int>&prices,int n,int ind,int buy,int cap,vector<vector<vector<int>>>&dp)
    {
        if(cap==0||ind==n)return 0;
        if(dp[ind][buy][cap]!=-1)
            return dp[ind][buy][cap];
        int profit=0;
        if(buy)
        {
            profit=max(-prices[ind]+f(prices,n,ind+1,0,cap,dp),f(prices,n,ind+1,1,cap,dp));
            
        }
        else
        {
             profit=max(prices[ind]+f(prices,n,ind+1,1,cap-1,dp),f(prices,n,ind+1,0,cap,dp));
        }
        return dp[ind][buy][cap]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
       vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        return f(prices,n,0,1,2,dp);
        
    }
};