//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  void dfs(int node,vector<int>adj[],int vis[])
{
     vis[node]=1;
      
       for(auto i:adj[node])
       {
           if(!vis[i])
           {
               vis[i]=1;
               dfs(i,adj,vis);
           }
       }
}
    int numProvinces(vector<vector<int>> adjm, int v) {
        // code here
       
        vector<int>adj[v];
        for(int i=0;i<v;i++)
        {
            for(int j=0;j<v;j++)
            {
                if(adjm[i][j]==1&&i!=j)
                {
                   adj[i].push_back(j);
                   adj[j].push_back(i);
                }
            }
        }
        int vis[v]={0};
       // vector<int>ans;
        int cnt=0;
        for(int i=0;i<v;i++)
        { if(!vis[i])
          {
            cnt++;
           dfs(i,adj,vis);
         }
          
        }
     return cnt;   
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends