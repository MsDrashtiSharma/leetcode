//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string longestPalin (string s) {
       if(s.length()<=1)
            return s;
        int max_len=1;
        int n=s.length();
        int st=0,end=0;

        
        //odd length
        
        for(int i=0;i<n-1;i++)
        {
            int l=i,r=i;
            while(l>=0&&r<n)
            {
                if(s[l]==s[r])
                {
                    l--;
                    r++;
                }else
                {
                    break;
                }
            }
            int len=r-l-1;
            if(len>max_len)
            {
                max_len=len;
                st=l+1;
                end=r-1;
            }
        }
        
                //even length
        
        for(int i=0;i<n-1;i++)
        {
            int l=i,r=i+1;
            while(l>=0&&r<n)
            {
                if(s[l]==s[r])
                {
                    l--;
                    r++;
                }else
                {
                    break;
                }
            }
            int len=r-l-1;
            if(len>max_len)
            {
                max_len=len;
                st=l+1;
                end=r-1;
            }
        }
        return s.substr(st,max_len);
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends