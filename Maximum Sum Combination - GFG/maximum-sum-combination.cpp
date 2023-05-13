//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> maxCombinations(int n, int k, vector<int> &a, vector<int> &b) {
        //   sort(A.begin(),A.end());

        // sort(B.begin(),B.end());

        // vector<int> ans;
      
         
        // priority_queue<pair<int,pair<int,int>>> pq;

        // for(int i=0;i<N;i++)

        // {

        //     pq.push({A[i]+B[N-1],{i,N-1}});

        // }
       

        // while(!pq.empty() && K--)

        // {

        //     pair<int,pair<int,int>> tp = pq.top();

        //     int vl = tp.first;

        //     int x = tp.second.first, y = tp.second.second;

        //     pq.pop();

        //     ans.push_back(vl);

        //     if(y != 0)

        //         pq.push({A[x]+B[y-1],{x, y-1}});

        // }

        //  return ans;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        vector<int>ans;
        priority_queue<pair<int,pair<int,int>>>pq;
        
        for(int i=0;i<n;i++)
        {
            pq.push({a[i]+b[n-1],{i,n-1}});
            
        }
        while(!pq.empty()&&k--)
        {
            pair<int,pair<int,int>>tp=pq.top();
            int vl=tp.first;
            int x=tp.second.first;
            int y=tp.second.second;
            
            pq.pop();
            ans.push_back(vl);
            if(y!=0)
            {
             pq.push({a[x]+b[y-1],{x,y-1}});   
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends