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
        vector<vector<int>>after(2,vector<int>(3,-1));
        vector<vector<int>>curr(2,vector<int>(3,-1));
        

        for(int ind=0;ind<n;ind++)
        {
            for(int buy=0;buy<=1;buy++)
            {
                curr[buy][0]=0;
            }
        }
        for(int buy=0;buy<=1;buy++)
        {
            for(int cap=0;cap<=2;cap++)
            {
                after[buy][cap]=0;
            }
        }
        
        for(int ind=n-1;ind>=0;ind--)
        {
            for(int buy=0;buy<=1;buy++)
            {    int profit=0;
                for(int cap=1;cap<=2;cap++)
                {
                    
                        if(buy)
                        {
                            profit=max(-prices[ind]+after[0][cap],after[1][cap]);

                        }
                        else
                        {
                             profit=max(prices[ind]+after[1][cap-1],after[0][cap]);
                        }  
                    
                        curr[buy][cap]=profit;
                }
             after=curr;
            }
        }
        
        
        
        
        
        
        return after[1][2];
        
    }
};