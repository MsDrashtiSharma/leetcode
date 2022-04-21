class Solution {
public:
    //tc=O(n^2)  sc=O(n^2)+O(n)-->auxillary space
  /*  int f(vector<int>& nums,int ind,int prev_ind,vector<vector<int>>&dp,int n)
    {
        if(ind==n)return 0;
        if(dp[ind][prev_ind+1]!=-1)
            return dp[ind][prev_ind+1];
         
        int len=0+f(nums,ind+1,prev_ind,dp,n);//not take
        if(prev_ind==-1||nums[ind]>nums[prev_ind])//take
        {
            len=max(len,1+f(nums,ind+1,ind,dp,n));
        }
        return dp[ind][prev_ind+1]=len;
    }
    
       int lengthOfLIS(vector<int>& nums) {
       int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return f(nums,0,-1,dp,n);
    }*/
    
    
    //tc=o(n^2)  sc=o(n^2)
  /*  int lengthOfLIS(vector<int>& nums) {
       int n=nums.size();
       vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int ind=n-1;ind>=0;ind--)
        {
            for(int prev_ind=ind-1;prev_ind>=-1;prev_ind--)
            {
                int len =0+dp[ind+1][prev_ind+1];
                if(prev_ind==-1||nums[ind]>nums[prev_ind])
                {
                    len=max(len,1+dp[ind+1][ind+1]);
                }
                dp[ind][prev_ind+1]=len;
            }
            
        }
        return dp[0][-1+1];
        */
    
      //tc=o(n^2)   sc=o(n*2)
    int lengthOfLIS(vector<int>& nums) {
       int n=nums.size();
       vector<int>after(n+1,0),curr(n+1,0);
        for(int ind=n-1;ind>=0;ind--)
        {
            for(int prev_ind=ind-1;prev_ind>=-1;prev_ind--)
            {
                int len =0+after[prev_ind+1];
                if(prev_ind==-1||nums[ind]>nums[prev_ind])
                {
                    len=max(len,1+after[ind+1]);
                }
                curr[prev_ind+1]=len;
            }
            after=curr;
            
        }
        return after[-1+1];
    }
      
    
    
    
};