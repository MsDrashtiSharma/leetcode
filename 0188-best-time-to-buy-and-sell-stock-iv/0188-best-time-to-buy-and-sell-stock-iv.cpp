class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
          int n=prices.size();
               vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        vector<vector<int>>after(2,vector<int>(k+1,-1));
        vector<vector<int>>curr(2,vector<int>(k+1,-1));
        

        for(int ind=0;ind<n;ind++)
        {
            for(int buy=0;buy<=1;buy++)
            {
                curr[buy][0]=0;
            }
        }
        for(int buy=0;buy<=1;buy++)
        {
            for(int cap=0;cap<=k;cap++)
            {
                after[buy][cap]=0;
            }
        }
        
        for(int ind=n-1;ind>=0;ind--)
        {
            for(int buy=0;buy<=1;buy++)
            {    int profit=0;
                for(int cap=1;cap<=k;cap++)
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
        
        
        
        
        
        
        return after[1][k];
      
    }
};