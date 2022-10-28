class Solution {
public:
    int f(vector<int>& prices,int buy,int ind,int& n, vector<vector<int>>&dp)
          {
           int profit=0;
            if(ind==n)
            {
                return 0;
            }
            if(dp[ind][buy]!=-1)
                return dp[ind][buy];
            if(buy)
            {
               profit=max(-prices[ind]+f(prices,0,ind+1,n,dp),f(prices,1,ind+1,n,dp));
            }
            else
            {
                profit=max(prices[ind]+f(prices,1,ind+1,n,dp),f(prices,0,ind+1,n,dp));
                
            }
                          return dp[ind][buy]=profit;
          }
    int maxProfit(vector<int>& prices) {
          int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
      
        return f(prices,1,0,n,dp);
            
        
        
    }
};