//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxProfit(int k, int n, int price[]) {
        // int n=price.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
        for(int i=n-1;i>=0;i--)
        {
            for(int buy=0;buy<=1;buy++)
            {  int profit=0;
                for(int cap=1;cap<=k;cap++)
                {
                if(buy==1)
                {
                    profit=max((-price[i]+dp[i+1][0][cap]),(0+dp[i+1][1][cap]));
                }
                else{
                    profit=max((price[i]+dp[i+1][1][cap-1]),(0+dp[i+1][0][cap]));
                     }
                 dp[i][buy][cap]=profit;
                }
            }
     
        }
        return dp[0][1][k];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}
// } Driver Code Ends