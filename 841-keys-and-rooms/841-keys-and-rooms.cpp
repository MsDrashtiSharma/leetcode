class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool>vis(rooms.size(),false);
            queue<int>q;
            q.push(0);
            vis[0]=true;
            while(!q.empty())
            {
                    int a=q.front();
                    q.pop();
                    for(auto u:rooms[a])
                    {
                            if(!vis[u])
                            {
                                    q.push(u);
                                    vis[u]=true;
                            }
                    }
            }
            for(int i=0;i<vis.size();i++)
            {
                    if (vis[i]==false)
                            return false;
                    
            }
            return true;
    }
};