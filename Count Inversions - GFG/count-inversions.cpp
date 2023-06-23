//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int merge(long long a[],long long low,long long mid,long long high)
    {
        vector<long long>temp;
        long long left=low;
        long long right=mid+1;
        long long int cnt=0;
        
        while(left<=mid&&right<=high)
        {
            if(a[left]<=a[right])
            {
                temp.push_back(a[left]);
                left++;
            }
            else{
                temp.push_back(a[right]);
                cnt+=(mid-left+1);
                right++;
            }
        }
            while(left<=mid)
            {
                temp.push_back(a[left]);
                left++;
            }
        
             while(right<=high)
            {
                temp.push_back(a[right]);
                right++;
            }
            for(int i=low;i<=high;i++)
            {
                a[i]=temp[i-low];
            }
        
        return cnt;
    }
    
    
    long long int mergesort(long long a[],long long low,long long high)
    {
       long long int cnt=0;
        if(low>=high)return cnt;
       long long mid=(low+high)/2;
        cnt+=mergesort(a,low,mid);
        cnt+=mergesort(a,mid+1,high);
        cnt+=merge(a,low,mid,high);
        return cnt;
    }
    long long int inversionCount(long long a[], long long n)
    {
        // Your Code Here
        return mergesort(a,0,n-1);
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends