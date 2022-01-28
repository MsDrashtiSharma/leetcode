class Solution {
public:
        
    bool isBipartite(vector<vector<int>>& graph) {
           /* int n=graph.size();
        vector<int>color(n,-1);
            for(int i=0;i<n;i++)
            {
                    if(color[i]==-1)
                    {queue<int>q;
                     q.push(i);
                    color[i]=1;
                     while(!q.empty())
                     {
                             int node=q.front();
                             q.pop();
                             for(auto it:graph[node])
                             {
                                     if(color[it]==-1)
                                     {
                                             color[it]=1-color[it];
                                             q.push(it);
                                     }
                                     else if(color[it]==color[node])
                                     { return false;}
                                     
                             }
                     }
                     
                            
                    }
                    
            }
            return true;
    }*/
       // {
        int n=graph.size();
        vector<int>colour(n,0);
        for(int i=0;i<n;i++)
        {
            if(colour[i]==0)
            {
                colour[i]=-1;
                queue<int>q;
                q.push(i);
                while(!q.empty())
                {
                    int x=q.front();
                    q.pop();
                    for(auto it:graph[x])
                    {
                        if(colour[it]==colour[x])
                        {
                            return false;
                        }
                        else if(colour[it]==0)
                        {
                            colour[it]=-colour[x];
                            q.push(it);
                        }
                    }
                }
            }
        }
        return true;
    }
            
           
            
    
};