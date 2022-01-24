class Solution {
public:
        bool dfs(int i,vector<int>adj[],int v[],int dv[])
        {
             v[i]=1;
                dv[i]=1;
                for(auto it:adj[i]){
                        if(!v[it]){
                                if(dfs(it,adj,v,dv))
                                   return true;
                        }    else if(dv[it])
                                   {
                                           return true;
                                   }
                        }
                                  dv[i]=0;
                                   return false;
        }
bool canFinish(int numcourses, vector<vector<int>>& prerequisites) {
      int v[numcourses],dv[numcourses];
        memset(v,0,sizeof v);
        memset(dv,0,sizeof v);
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
    }
        
};