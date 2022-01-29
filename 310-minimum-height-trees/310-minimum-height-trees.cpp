class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
      if(n==1)
                return {0};
            vector<unordered_set<int>>adj(n);
            for(auto i:edges)
            {
                    adj[i[0]].insert(i[1]);
                    adj[i[1]].insert(i[0]);
            }
            queue<int>q;
            for(int i=0;i<adj.size();++i)
            {
                    if(adj[i].size()==1)
                            q.push(i);
            }
            while(n>2)
            {
                    int len=q.size();
                    n=n-len;
                    for(int i=0;i<len;i++)
                    {
                            int node=q.front();
                            q.pop();
                            for(auto a:adj[node])
                            {
                                    adj[a].erase(node);
                                    if(adj[a].size()==1)
                                            q.push(a);
                                            
                            }
                    }
                    
            }
            vector<int>res;
            while(!q.empty())
            {
                    res.push_back(q.front());
                    q.pop();
            }
            return res;
    }
                   

};