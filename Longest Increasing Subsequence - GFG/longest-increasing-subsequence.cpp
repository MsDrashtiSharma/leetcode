//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int f(int i,int previ,int a[],int n,vector<vector<int>>&dp)
    {
        if(i==n)return 0;
        if(dp[i][previ+1]!=-1)return dp[i][previ+1];
        int len=f(i+1,previ,a,n,dp);
        if(previ==-1||a[i]>a[previ])
        {
             len=max(len,1+f(i+1,i,a,n,dp));
        }
        return dp[i][previ+1]=len;
    }
    int longestSubsequence(int n, int a[])
    {
       // your code herer
       vector<vector<int>>dp(n+1,vector<int>(n+1,0));
       vector<int>front(n+1,0),curr(n+1,0);
       for(int i=n-1;i>=0;i--)
       {
           for(int previ=i-1;previ>=-1;previ--)
           {
                int len=front[previ+1];
                if(previ==-1||a[i]>a[previ])
                {
                     len=max(len,1+front[i+1]);
                }
                 curr[previ+1]=len;
           }
          front=curr;
       }
       return curr[-1+1];
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends