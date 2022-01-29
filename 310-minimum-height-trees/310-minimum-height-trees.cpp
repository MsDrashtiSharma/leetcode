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
                            {//we use erase we are using unorered_set in creating adj list not like normal we can npt use vector<vector<int>> to create adj list bcoz in thi sol we havev to remove eleemnet from list serially which is not poosible in vector<vector<int>> bcoz it use pop_back to delete the last node not the spcified or a particaluar node which we want so we use unorded_set bcoz of which we use erase 
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