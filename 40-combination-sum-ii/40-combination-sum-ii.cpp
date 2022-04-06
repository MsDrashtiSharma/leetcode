class Solution {
public:
    
       void findcombination(int ind,int target,vector<int>&candi,vector<vector<int>>&ans,vector<int>&ds)
    {
     if(target==0)
     {ans.push_back(ds);
        return;
     }
              
                
    for(int i=ind;i<candi.size();i++)
    {
        if(i>ind && candi[i]==candi[i-1]) continue;
        if(candi[i]>target)
            break;
        ds.push_back(candi[i]);
        findcombination(i+1,target-candi[i],candi,ans,ds);
        ds.pop_back();
     }
}
    
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
       sort(candidates.begin(),candidates.end());
         vector<vector<int>>ans;
        vector<int>ds;
        findcombination(0,target,candidates,ans,ds);
        return ans;
        }
 
    
};