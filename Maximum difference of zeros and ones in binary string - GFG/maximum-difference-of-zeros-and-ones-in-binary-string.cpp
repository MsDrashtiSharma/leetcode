//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int maxSubstring(string s)
	{
	     int cur=0,maxi=0;
         for(int i=0; i<s.size(); i++ ) {
             if(s[i]=='1') cur--;
             else cur++;
             maxi=max(maxi,cur);
             if(cur<0) cur=0;
         }
         if(!maxi) return -1;
         return maxi;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.maxSubstring(s) << "\n";
   	}

    return 0;
}

// } Driver Code Ends