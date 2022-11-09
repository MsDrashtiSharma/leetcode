class Solution {
public:
    int f(int i,int k,vector<int>&arr,int n, vector<int>&dp)
    {
        if(i==n)return 0;
        int maxi=INT_MIN;
        int maxans=INT_MIN;
        if(dp[i]!=-1)
            return dp[i];
        int len=0;
        for(int j=i;j<min(i+k,n);j++)
        {
            len++;
            maxi=max(maxi,arr[j]);
            int sum=len*maxi+f(j+1,k,arr,n,dp);
            maxans=max(maxans,sum);
        }
        return dp[i]=maxans;
        
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dp(n+1,0);
        
        for(int i=n;i>=0;i--)
        {   int maxi=INT_MIN;
            int maxans=INT_MIN;

            int len=0;
            if(i==n)continue;
            for(int j=i;j<min(i+k,n);j++)
        {
            len++;
            maxi=max(maxi,arr[j]);
            int sum=len*maxi+dp[j+1];
            maxans=max(maxans,sum);
        }
            dp[i]=maxans;
        }
        return dp[0];
    }
};