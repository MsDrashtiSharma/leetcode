class Solution {
public:
     /*   bool dfs(int i,vector<int>adj[],bool v[],bool dv[])
        {
             v[i]=true;
                dv[i]=true;
                for(auto it:adj[i]){
                        if(!v[it]){
                                if(dfs(it,adj,v,dv))
                                   return true;
                        }    else if(dv[it])
                                   {
                                           return true;
                                   }
                        }
                                  dv[i]=false;
                                   return false;
        }
bool canFinish(int numcourses, vector<vector<int>>& prerequisites) {
      bool v[numcourses],dv[numcourses];
        memset(v,false,sizeof v);
        memset(dv,false,sizeof v);
    vector<int>adj[numcourses];
        for(int i=0;i<prerequisites.size();i++)
        {
                adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
            for(int i=0;i<numcourses;i++)
            {
                    if(!v[i])
                    {
                            if(dfs(i,adj,v,dv))
                           
                                    return false;
                            
                    }
                    
            }
            return true;
    }*/
        bool canFinish(int numcourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>>adj(numcourses,vector<int>());
            for(vector<int>&pre:prerequisites)
                    adj[pre[0]].push_back(pre[1]);
            vector<int>v(numcourses,0);
            vector<int>dv(numcourses,0);
            for(int i=0;i<numcourses;i++)
            {
                    if(!v[i])
                    {
                            if(dfs(i,adj,v,dv))
                            {
                                    return false;
                            }
                    }
                    
            }
            return true;
    }
        bool dfs(int i,vector<vector<int>>&adj,vector<int>&v,vector<int>&dv)
        {
             v[i]=1;
                dv[i]=1;
                for(auto it:adj[i])
                {
                        if(!v[it])
                        {
                                if(dfs(it,adj,v,dv))
                                   return true;
                        }
                                   else if(dv[it])
                                   {
                                           return true;
                                   }
                        
                }
                                  dv[i]=0;
                                   return false;
        }
        
};