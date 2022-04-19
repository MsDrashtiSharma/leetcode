class Solution {
public:
   /* int f(int ind,int buy,vector<int>& prices,int n, vector<vector<vector<int>>>&dp,int cap)
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
    }*/
    
    
       int maxProfit(vector<int>& prices) {
       int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
       for(int ind=0;ind<=n;ind++)
        {
            for(int buy=0;buy<=1;buy++)
            {
                dp[ind][buy][0]=0;
            }
        }
     
            for(int buy=0;buy<=1;buy++)
            { for(int cap=0;cap<=2;cap++)
               {
                dp[n][buy][cap]=0;
               }
            }
      
              for(int ind=n-1;ind>=0;ind--)
           {
               for(int buy=0;buy<=1;buy++)
                   
               {   int profit=0;
                   for(int cap=1;cap<=2;cap++)
                   {
                                  if(buy==1)
                        {
                             profit=max(-prices[ind]+dp[ind+1][0][cap],0+dp[ind+1][1][cap]);
                        }
                       else
                       {
                               profit=max(prices[ind]+dp[ind+1][1][cap-1],0+dp[ind+1][0][cap]);            
                       }
                     dp[ind][buy][cap]=profit;  
                   }
               }
           }
         return dp[0][1][2];
     
           
       }
    
    
};