class Solution {
public:
    int pivotIndex(vector<int>& nums) {
//         int a=0,sum1=0,b=-1,sum=0;
//         int count=-1;
//         for(int i=0;i<nums.size()-1;i++)
//         {    
//             if(i==0)
//             {
//                 for(int k=1;k<nums.size();k++)
//                 {
//                     sum+=nums[k];
//                 }
//                 if(sum==0)
//                 {
//                     b=0;
//                     break;
//                 }    
//             }
            
//                 a+=nums[i];
//             count++;
//             sum1=0;
//             for(int j=i+2;j<nums.size();j++)
//             {
//                 sum1+=nums[j];
//             }
//             if(a==sum1)
//             {
//                 b=count+1;
//                 break;
//             } 
             
//             if(i==n-1)
//             {
//                 for(int k=0;k<nums.size()-1;k++)
//                 {
//                     sum+=nums[k];
//                 }
//                 if(sum==0)
//                 {
//                     b=5;
//                     break;
//                 }    
//             }
           
//         }
//         return b;
//    
        int rightSum = accumulate(nums.begin(), nums.end(), 0);
        // Initialize leftSum to store the sum of all the numbers strictly to the index's left...
        int leftSum = 0;
        // Traverse all elements through the loop...
        for (int idx = 0; idx < nums.size(); idx++) {
            // subtract current elements with from rightSum...
            rightSum -= nums[idx];
            // If the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right...
            if (leftSum == rightSum)
                return idx;     // Return the pivot index...
            // add current elements with leftSum...
            leftSum += nums[idx];
        }
        return -1;      // If there 
    }
};