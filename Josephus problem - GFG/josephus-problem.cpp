// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
/*You are required to complete this method */
void solve(int index,int k,vector<int>v,int &ans)
{
    if(v.size()==1)
    {
        ans=v[0];
        return  ;
    }
     index=(index+k)%v.size();
    v.erase(v.begin()+index);
    solve(index,k,v,ans);
    
}
class Solution
{
    public:
    int josephus(int n, int k)
    {
       //Your code here
       vector<int>v;
      int ans=0;
       for(int i=1;i<=n;i++)
      v.push_back(i);
         k=k-1;
   
     solve(0,k,v,ans); 
     return ans;
    }
};



// { Driver Code Starts.

int main() {
	
	int t;
	cin>>t;//testcases
	while(t--)
	{
		int n,k;
		cin>>n>>k;//taking input n and k
		
		//calling josephus() function
		Solution ob;
		cout<<ob.josephus(n,k)<<endl;
	}
	return 0;
}  // } Driver Code Ends