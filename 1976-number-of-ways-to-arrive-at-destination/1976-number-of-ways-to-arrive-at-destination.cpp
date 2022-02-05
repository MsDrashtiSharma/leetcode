class Solution {
public:
    typedef long long ll;
    typedef pair<long long,long long>ppl;
    int countPaths(int n, vector<vector<int>>& roads) {
    int mod=(1e9+7);
        vector<ll>dis(n,LLONG_MAX);
        vector<int>ways(n,0);
        priority_queue<ppl,vector<ppl>,greater<ppl>>pq;
        dis[0]=0;
        ways[0]=1;
        pq.push({0,0});
        vector<ppl>adj[n];
        //mAKINg adj list
        for(auto x:roads)
        {
            adj[x[0]].push_back({x[1],x[2]});
            adj[x[1]].push_back({x[0],x[2]});
        }
        while(!pq.empty())
        {
            ll distance=pq.top().first;
            ll node=pq.top().second;
            pq.pop();
            for(auto x:adj[node])
            {
                ll adjnode=x.first;
                ll nextdis=x.second;
                if(dis[adjnode]>distance+nextdis)
                {
                    dis[adjnode]=distance+nextdis;
                    ways[adjnode]=ways[node];
                    pq.push({dis[adjnode],adjnode});
                    
                }
                else if(distance+nextdis==dis[adjnode])
                {ways[adjnode]=(ways[adjnode]+ways[node])%mod;}
            }
        }
        return ways[n-1];
    }
    
};