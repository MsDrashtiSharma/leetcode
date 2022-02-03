class Solution {
public:
        int findparent(vector<int>&parent,int i)
        {
                if(parent[i]==-1)
                        return i;
                return parent[i]=findparent(parent,parent[i]);
        }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
           //     stack<pair<int,int>>s;
            vector<int>ans;
            vector<int>parent(n+1,-1);
        for(int i=0;i<n;i++)
       {
        int u=edges[i][0];
        int v=edges[i][1];
        
        int src=findparent(parent,u);
        int des=findparent(parent,v);
                {
                        if(src!=des)
                        {
                                parent[src]=des;
                        }
                        else
                        {      ans.clear();
                                ans.push_back(u);
                                ans.push_back(v);
                        }
                }
                
       }
             //ans.push_back(s.top());
            return ans;
    }
};