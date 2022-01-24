class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        /*simple approch
            int a=edges[0][0];
            int b=edges[0][1];
            if(a==edges[1][0]||a==edges[1][1])
                    return a;
            else
                    return b;
                    */
            
            
            //indegree approch
int n=0;
            for(int i=0;i<edges.size();i++)
               n=max(n,max(edges[i][0],edges[i][1]));
            vector<int>indegree(n+1);
            for(int i=0;i<edges.size();i++)
            {
                    indegree[edges[i][0]]++;
                    indegree[edges[i][1]]++;
                    
            }int res=0;
            for(int i=0;i<indegree.size();i++)
            {
                    if(indegree[i]==n-1)
                    {
                            res=i;
                            break;
                    }
            }
            return res;
    }
};