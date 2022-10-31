class Solution {
public:
    int f(vector<int>&nums,int ind,int prev_ind,int n,vector<vector<int>>&dp){
        if(ind==n)
            return 0;
        if(dp[ind][prev_ind+1]!=-1)
            return dp[ind][prev_ind+1];
        int len=0+f(nums,ind+1,prev_ind,n,dp);
        if(prev_ind==-1||nums[ind]>nums[prev_ind])
        {
           len=max(len,1+f(nums,ind+1,ind,n,dp));
        }
        return dp[ind][prev_ind+1]=len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        // vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        // vector<int>curr(n+1,0);
        // vector<int>after(n+1,0);
        // for(int ind=n-1;ind>=0;ind--)
        // {
        //     for(int prev_ind=ind-1;prev_ind>=-1;prev_ind--)
        //     {
        //          int len=0+after[prev_ind+1];
        //         if(prev_ind==-1||nums[ind]>nums[prev_ind])
        //         {
        //            len=max(len,1+after[ind+1]);
        //         }
        //         curr[prev_ind+1]=len;
        //     }
        //     after=curr;
        // }
        // return after[-1+1];
        
        
        // vector<int>dp(n,1);
        // int maxi=1;
        // for(int i=0;i<n;i++)
        // {
        //     for(int prev=0;prev<i;prev++)
        //     {
        //         if(nums[prev]<nums[i])
        //         {
        //             dp[i]=max(dp[i],1+dp[prev]);
        //         }
        //     }
        //     maxi=max(maxi,dp[i]);
        // }
        // return maxi;
        
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
                int ind=lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
                temp[ind]=nums[i];
            }
        }
        return len;
    }
};