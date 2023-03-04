//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    int minimumNumberOfSwaps(string s){
        // vector<int>v;
         int n=s.size();
        // for(int i=0;i<n;i++)
        // if(s[i]=='[')v.push_back(i);
        
        // int ind=0;
        // int ans=0;
        // int count=0;
        // for(int i=0;i<n;i++)
        // {
        //     if(s[i]=='[')
        //     {
        //         count++;
        //         ind++;
        //     }
        //     else
        //     {
        //         count--;
        //         if(count<0)
        //         {
        //             ans+=v[ind]-i;
        //             swap(s[i],s[v[ind]]);
        //             count=1;
        //             ind++;
        //         }
        //     }
        // }
        // return ans;
        int ans=0;
        int open=0;
        int close=0;
        int fault=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]==']')
            {
                close++;
                fault=close-open;
            }
            else
            {
              open++;
              if(fault>0)
              ans+=fault;
              fault--;
            }
        }
        return ans;
    }    
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.minimumNumberOfSwaps(S) << endl;
    }
    return 0; 
} 
// } Driver Code Ends