class Solution {
public:
        int dfs(vector<vector<int>>&adj,vector<int>&ans, vector<int>& quiet,int i)
        {
                if(ans[i]!=-1)
                        return ans[i];
                
                ans[i]=i;
          for(auto adjnode:adj[i])
          {int ans_adj=dfs(adj,ans,quiet,adjnode);
              if(quiet[ans_adj]<quiet[ans[i]])
              {
                      ans[i]=ans_adj;
              }
          }
                return ans[i];
        }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        
            
            int n=quiet.size();
            vector<vector<int>>adj(n);
            for(auto rich:richer)
            {
                    adj[rich[1]].push_back(rich[0]);
            }
            vector<int>ans(n,-1);
            for(int i=0;i<n;i++)
            {
                    if(ans[i]==-1)
                    {
                            dfs(adj,ans,quiet,i);
                    }
            }
            return ans;
 }
};