class Solution {
public:
    /*int maxProfit(int k, vector<int>& prices) {
       int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,-1)));
       for(int ind=0;ind<=n;ind++)
        {
            for(int buy=0;buy<=1;buy++)
            {
                dp[ind][buy][0]=0;
            }
        }
     
            for(int buy=0;buy<=1;buy++)
            { for(int cap=0;cap<=k;cap++)
               {
                dp[n][buy][cap]=0;
               }
            }
      
              for(int ind=n-1;ind>=0;ind--)
           {
               for(int buy=0;buy<=1;buy++)
                   
               {   int profit=0;
                   for(int cap=1;cap<=k;cap++)
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
         return dp[0][1][k];
     
         */
        
        
        
        
        //space optimaxtion in dp[2][k]
      /*  int n=prices.size();
        vector<vector<int>>after(2,vector<int>(k+1,0));
        vector<vector<int>>curr(2,vector<int>(k+1,0));
      
              for(int ind=n-1;ind>=0;ind--)
           {
               for(int buy=0;buy<=1;buy++)
                   
               {   int profit=0;
                   for(int cap=1;cap<=k;cap++)
                   {
                                  if(buy==1)
                        {
                             profit=max(-prices[ind]+after[0][cap],0+after[1][cap]);
                        }
                       else
                       {
                               profit=max(prices[ind]+after[1][cap-1],0+after[0][cap]);            
                       }
                    curr[buy][cap]=profit;  
                   }
                
               }
               after=curr;
           }
         return after[1][k];
     
      }
           
   */    
    int f(int ind,int transno,vector<int>prices,int n,int k,vector<vector<int>>&dp)
    {if(ind==n||transno==2*k)
        return 0;
     if(dp[ind][transno]!=-1)
         return dp[ind][transno];
     if(transno%2==0)
     {
        // return dp[ind][transno]=max(-prices[ind]+dp[ind+1][transno+1],0+dp[ind+1][tansno]);
          return dp[ind][transno]=max(-prices[ind]+f(ind+1,transno+1,prices,n,k,dp),0+f(ind+1,transno,prices,n,k,dp));
     }
        else
        {
            return dp[ind][transno]=max(prices[ind]+f(ind+1,transno+1,prices,n,k,dp),0+f(ind+1,transno,prices,n,k,dp));

         //return dp[ind][transno]=max(prices[ind]+dp[ind+1][transno+1],0+dp[ind+1][tansno]);
        }
     //return dp[0][0];
    }
    int maxProfit(int k, vector<int>& prices) 
    {  int n=prices.size();
       vector<vector<int>>dp(n,vector<int>(2*k,-1));
        return f(0,0,prices,n,k,dp);
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
};