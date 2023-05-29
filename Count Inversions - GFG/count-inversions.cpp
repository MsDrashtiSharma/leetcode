//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    
    long long int merge(long long  arr[],long long  temp[],int left,int mid,int right)
    {
        long long int inv_count=0;
        int i=left;
        int j=mid;
        int k=left;
        while((i<=mid-1)&&(j<=right))
        {
            if(arr[i]<=arr[j])
            {
                temp[k++]=arr[i++];
            }
            else{
                temp[k++]=arr[j++];
                inv_count+=(mid-i);
            }
        }
        while(i<=mid-1)
        {
            temp[k++]=arr[i++];
        }
        while(j<=right)
        {
            temp[k++]=arr[j++];
        }
        for(i=left;i<=right;i++)
        {
            arr[i]=temp[i];
        }
        return inv_count;
        
    }
    long long int mergesort(long long arr[],long long  temp[],int left,int right)
    {
         int mid;
        long long int inv_count=0;
        if(right>left)
        {
        mid=(left+right)/2;
        inv_count+=mergesort(arr,temp,left,mid);
        inv_count+=mergesort(arr,temp,mid+1,right);
        inv_count+=merge(arr,temp,left,mid+1,right);  
        }
        return inv_count;
       
    }
    long long int inversionCount(long long arr[], long long n)
    {
        // Your Code Here
        long long  temp[n];
        long long int ans=mergesort(arr,temp,0,n-1);
        return ans;
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