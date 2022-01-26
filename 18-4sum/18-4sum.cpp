class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>res;
            if(nums.empty())
                    return res;
            int n=nums.size();
            sort(nums.begin(),nums.end());
            for(int i=0;i<n;i++)
            {
                    for(int j=i+1;j<n;j++)
                    {
                            int target2=target-nums[i]-nums[j];
                            int front=j+1;
                            int back=n-1;
                            while(front<back)
                            {
                                    int twosum=nums[front]+nums[back];
                                    if(twosum<target2)front++;
                                   else if(twosum>target2)back--;
                                    else{
                                            vector<int>quard(4,0);
                                            quard[0]=nums[i];
                                            quard[1]=nums[j];
                                            quard[2]=nums[front];
                                            quard[3]=nums[back];
                                            res.push_back(quard);
                                    
                                    while(front<back&&nums[front]==quard[2])++front;
                                    while(front<back&&nums[back]==quard[3])--back;
                                    
                                    }
                            }
                    
                    while(j+1<n&&nums[j+1]==nums[j])++j;
                    
                    
            }
             while(i+1<n&&nums[i+1]==nums[i])++i;
    }
            return res;
    }
};