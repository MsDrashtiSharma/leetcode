//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& m, int n) 
    {
        stack<int>s;
        for(int i=0;i<n;i++)
        {
            s.push(i);
        }
        while(s.size()>1)
        {
           int a=s.top();
           s.pop();
           int b=s.top();
           s.pop();
           if(m[a][b]==1)
           {
               s.push(b);
           }
           else{
               s.push(a);
           }
        
        }
        int ans=s.top();
        int onecount=0,zerocount=0;
        for(int i=0;i<n;i++)
        {
            if(m[ans][i]==0)
            zerocount++;
            if(m[i][ans]==1)
            onecount++;
        }
        if(zerocount!=n||onecount!=n-1)
        return -1;
        else
        return ans;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
    //      stack<int>s;
    //     for(int i=0;i<n;i++)
    //     {
    //         s.push(i);
    //     }
    //     while(s.size()>1)
    //     {
    //         int a=s.top();
    //         s.pop();
    //         int b=s.top();
    //         s.pop();
    //         if(M[a][b]==1)//if(a know b)
    //         {
    //             s.push(b);
    //         }
    //         else//if b know a
    //         {
    //             s.push(a);
    //         }
    //     }
        
        
    //     // 0 1 0
    //     // 0 0 0
    //     // 0 0 1
        
        
    //     // s 0 1 2
    //     // a=2
    //     // b=1
    //     // 2 1
    //     // 0 2 
    //     // s 2
    //     int ans=s.top();
    //   // s.pop();
    //     int zerocount=0;
    //     int onecount=0;
    //     for(int i=0;i<n;i++)
    //     {
    //         if(M[ans][i]==0)
    //         zerocount++;
    //         if(M[i][ans]==1)
    //         onecount++;
    //     }
    //     if(zerocount!=n||onecount!=n-1)
    //     return -1;
    //     else 
    //     return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends