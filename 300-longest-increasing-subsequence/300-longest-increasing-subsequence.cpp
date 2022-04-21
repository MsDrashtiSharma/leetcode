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
  /*  int lengthOfLIS(vector<int>& nums) {
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
    */
    
    
    
//USING TABULATION ALGORITHM OR TABULATION ANOTHER APPROACH   tc=O(n*n)   sc=O(n)
  /* int lengthOfLIS(vector<int>& nums) {
       int n=nums.size();
       vector<int>dp(n,1);
       int maxi=1;
       for(int ind=0;ind<n;ind++)
      {
           for(int prev_ind=0;prev_ind<ind;prev_ind++)
           {
               if(nums[prev_ind]<nums[ind])
               {
                   dp[ind]=max(dp[ind],1+dp[prev_ind]);
               }
           }
           maxi=max(maxi,dp[ind]);
       }
       
       return maxi;
   }*/
       
      //to print longest incresing subsequence   tc=o(n^2) sc=o(n) 
   /*    int lengthOfLIS(vector<int>& nums) {
       int n=nums.size();
           int maxi=1;
           int lastindex=0;
       vector<int>dp(n,1),hash(n);
           for(int i=0;i<n;i++)
           {
               hash[i]=i;
               for(int prev=0;prev<i;prev++)
               {
                   if(nums[prev]<nums[i]&&1+dp[prev]>dp[i])
                   {
                       dp[i]=1+dp[prev];
                       hash[i]=prev;
                   }
               }
                    if(dp[i]>maxi)
                    {
                        maxi=dp[i];
                        lastindex=i;
                    }
           }
           vector<int>temp;
           temp.push_back(nums[lastindex]);
           while(hash[lastindex]!=lastindex){
              lastindex=hash[lastindex];
           temp.push_back(nums[lastindex]);
           }
           
           reverse(temp.begin(),temp.end());
           for(auto it:temp)cout<<it<<" "<<endl;
           return maxi;
       }
       
       
       
    
    */
    
    int lengthOfLIS(vector<int>& nums) {
       int n=nums.size();
       vector<int>temp;
        temp.push_back(nums[0]);
        int len=1;
        for(int i=1;i<n;i++)
        {
            if(nums[i]>temp.back())
            {
                temp.push_back(nums[i]);
                len++;
            }
            else
            {
                auto ind=lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
                temp[ind]=nums[i];
            }
        }
    return len;
    }
    
};