class Solution {
public:
        int findparent(vector<int>& parent,int i)
        {
                if(parent[i]==-1)
                {
                        return i;
                        
                }
                return parent[i]=findparent(parent,parent[i]);
        }
      
        int findCircleNum(vector<vector<int>>& c)
        {
        int n =c.size();
        vector<int>parent(n+1,-1);
            int ans=n;
            for(int i=0;i<n;i++)
            {
                    for(int j=0;j<n;j++)
                    {
                            if(i==j||c[i][j]==0)
                                    continue;
                            int src=findparent(parent,i);
                            int des=findparent(parent,j);
                           // if(c[i][j])
                            { if(src!=des&&(c[i][j]))
                            {
                                    ans--;
                                    parent[src]=des;
                            }
                            }
                    }
            }
            return ans;
    }
};