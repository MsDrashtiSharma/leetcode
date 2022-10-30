class Solution {
public:
    int f(int ind,int buy,vector<int>&prices,int n,vector<vector<int>>&dp)
    {
        if(ind>=n)
            return 0;
        if(dp[ind][buy]!=-1)
            return dp[ind][buy];
        int profit=0;
        if(buy)
        {
           profit=max(-prices[ind]+f(ind+1,0,prices,n,dp),f(ind+1,1,prices,n,dp)); 
        }
        else
        {
            profit=max(prices[ind]+f(ind+2,1,prices,n,dp),f(ind+1,0,prices,n,dp));
        }
        return dp[ind][buy]=profit;
        
    }
    int maxProfit(vector<int>& prices)
    {
        int n=prices.size();
        vector<vector<int>>dp(n+2,vector<int>(2,0));
        vector<int>after1(2,0);
        vector<int>after(2,0);
        vector<int>curr(2,0);
         for(int ind=n-1;ind>=0;ind--)
         { int profit=0;
             for(int buy=0;buy<=1;buy++)
             {
                 if(buy)
                {
                   profit=max(-prices[ind]+after[0],after[1]); 
                }
                else
                {
                    profit=max(prices[ind]+after1[1],after[0]);
                }
                 curr[buy]=profit;
             }
          after1=after;
          after=curr;
         }
        
        
        
        
        
        return curr[1];
    }
};