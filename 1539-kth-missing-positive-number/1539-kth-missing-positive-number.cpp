class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
      if(k<arr[0])
              return k;
            int l=0;
            int r=arr.size()-1;
            
            while(l<=r)
            {
                int mid=(l+r)/2;
                    if((arr[mid]-(mid+1))<k)
                       l=mid+1;
                       else
                       r=mid-1;
            }
                       return l+k;
            /*let assume [arr[mid]-(mid+1)]=x
            (x<k) is to see how many no. are missing n we have to reach the  possible number just greater then  k in this example first it is 6>k
            that is number at arr[mid](which is 11)
            left behind 6 no. to at 4 index ........l+1 is that [1,2,3,4,5,6.....]
            they are on index 0,1,2,3,4,5.....
            
            return l+k becozto see how many steps we have to go ahead from arr[l]
            which is ((arr[mid]-(mid+1))-k+1) which according to example 1 is 2 step ahead and the vallue 2 step ahead is [arr[mid]-(arr[mid]-(mid+1))-k+1]which bsaiically is l+k
            so its returnesd as 2 from 11 taht is 9 as per 1 example*/
    }
};