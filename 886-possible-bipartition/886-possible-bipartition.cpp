class Solution {
public:
        bool bipartite(vector<int>&color,int i,vector<int>adj[])
        {
                if(color[i]==-1)
                 color[i]=1;
                for(auto ad:adj[i])
                {
                        if(color[ad]==-1)
                        {
                                color[ad]=1-color[i];
                                if(!bipartite(color,ad,adj))
                                        return false;
                                
                        }
                        else if(color[ad]==color[i])
                                return false;
                }
                return true;
        }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
            vector<int>adj[n+1];
       for(auto i:dislikes)
       {
               adj[i[0]].push_back(i[1]);
               adj[i[1]].push_back(i[0]);
       }
            
         vector<int>color(n+1,-1);
            for(int i=0;i<n;i++)
            {
                    if(color[i]==-1)
                    {
                            if(!bipartite(color,i,adj))
                                    return false;
                    }
            }
            return true;
    }
};