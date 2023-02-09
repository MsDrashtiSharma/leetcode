//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int maxSumPairWithDifferenceLessThanK(int a[], int N, int K)
    {
        // Your code goes here   
        sort(a,a+N,greater<int>());
        int sum=0;
        int i=0;
        while(i<N-1)
        {
            if(abs(a[i]-a[i+1])<K)
            {
                sum+=a[i];
                sum+=a[i+1];
                i+=2;
            }
            else
            i++;
        }
        return sum;
        //17 15 12 10 9 5 3 
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int N;
		cin>>N;
		int arr[N];
		for(int i=0;i<N;i++)
		cin>>arr[i];

		int K;
		cin>>K;
        Solution ob;
		cout<<ob.maxSumPairWithDifferenceLessThanK(arr,N,K)<<endl;
	}
	return 0;
}

// } Driver Code Ends