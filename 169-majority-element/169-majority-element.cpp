class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=0;
            int ele=0;
            for(auto num:nums)
            {
                    if(cnt==0)
                            ele=num;
                    if(ele==num)
                    {
                            cnt=cnt+1;
                    }
                    else
                            cnt=cnt-1;
                    
            }
            return ele;
    }
};