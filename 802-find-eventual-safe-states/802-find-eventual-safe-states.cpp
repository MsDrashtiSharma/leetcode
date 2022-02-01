class Solution {
public:
        int dfs(vector<vector<int>>&graph,int i,vector<int>&vis,vector<int>&dfsvis,vector<int>&parentcycle)
        {
                vis[i]=1;
                dfsvis[i]=1;
                vector<int>data=graph[i];
                for(auto x:data)
                {
                        if(!vis[x])
                        {
                          if(dfs(graph,x,vis,dfsvis,parentcycle))
                                return parentcycle[i]=1;
                        }
                        else if(dfsvis[x])
                                return parentcycle[i]=1;
                        
                }
                dfsvis[i]=0;
                return 0;
        }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
            int n=graph.size();
        vector<int>vis(n+1,0);
        vector<int>dfsvis(n+1,0);
            vector<int>parentcycle(n+1,0);
            vector<int>ans;
                    
            for(int i=0;i<graph.size();i++)
            {
                   if(!vis[i])
                    dfs(graph,i,vis,dfsvis,parentcycle);
            }
            for(int i=0;i<graph.size();i++)
            {
                    if(!parentcycle[i])
                            ans.push_back(i);
            }
            return ans;
            
    }
};