class Solution {
public:
      /*  bool findtoposort(int node,vector<int>&v,stack<int>&s,vector<int>&adj)
        {
                v[node]=1;
                for(auto it:adj[node])
                {
                        if(v[it]==1)
                                return true;
                        if(!v[it])
                        {
                               if( findtoposort(it,v,s,adj))
                                       return true;
                        }
                }
                s.push(node);
                return  false;
        }
        
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
         stack<int>s;
        vector<int>v(numCourses,0);
           vector<vector<int>>adj(numCourses);
            for(auto i: prerequisites)
            {
                   adj[i[0]].push_back(i[1]);
            }
            
         for(int i=0;i<numCourses;i++)
          {
              if((v[i]==0)&&findtoposort(i,v,s,adj))return {};
          }
            vector<int>topo;
            while(!st.empty())
            {
                    topo.push_back(st.top());
                    st.pop();
            }
            return topo;
    }*/
       // class Solution {
//public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<int> adjList[n];
        vector<int> ind(n, 0);
        vector<int> ts;
        
        for(auto pre : prerequisites){
            adjList[pre[1]].push_back(pre[0]);
            ind[pre[0]]++;
        }
        
        queue<int> q;
        for(int i = 0; i < n; ++i) if(ind[i] == 0) q.push(i);
        
        while(!q.empty()){
            int top = q.front(); q.pop(); n--;
            ts.push_back(top);
            for(auto x : adjList[top]){
                if(--ind[x] == 0) q.push(x);
            }
        }
        
        if(n == 0) return ts;
        return vector<int>();
    }
//};

};