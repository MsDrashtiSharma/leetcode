class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int min_price=INT_MAX;
     int profit=0;
     for(int i=0;i<prices.size();i++)
      {
         min_price=min(prices[i],min_price);
      profit=max(profit,prices[i]-min_price);
    }
         return profit;
        
        //wrong code with me need some correction fr correct                 //ans
 //       int start =0;
   //     int result,maxi;
     //   for(int i=0;i<prices.size()-1;i++)
       // {  int value=prices[i];
  //          for(int j=i+1;j<prices.size();j++)
    //        { 
      //         maxi=INT_MAX;
        //       maxi=min(maxi,prices[j]);
                
         //   }
          // cout<<maxi<<endl<<"m";
        //    if(maxi<value);
          // {result=value-maxi;
           // cout<<result<<endl<<"r";
         //   start=max(start,result);
           // cout<<start<<endl<<"s";
            }
       // }
    //    return start;
        
      //   }
};