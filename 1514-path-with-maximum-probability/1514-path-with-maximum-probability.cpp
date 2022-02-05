class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<int,double>>g[n];
        for(int i=0;i<edges.size();i++)
        {
            g[edges[i][0]].push_back({edges[i][1],succProb[i]});
              g[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        vector<double>dis(n,INT_MIN);
        priority_queue<pair<double,int>>pq;
        dis[start]=1.00000;
        pq.push({1.00000,start});
        while(!pq.empty())
        {
            auto x=pq.top();
            pq.pop();
            int u=x.second;
            for( auto it:g[u])
            {
                int v=it.first;
                double wt=it.second;
                if(dis[v]<dis[u]*wt)
                {
                    dis[v]=dis[u]*wt;
                    pq.push({dis[v],v});
                }
            }
        }
        if(dis[end]==INT_MIN)
            return 0.00000;
        else
          return  dis[end];
    }
};