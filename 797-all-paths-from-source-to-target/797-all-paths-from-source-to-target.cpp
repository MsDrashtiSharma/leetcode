class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
           queue<vector<int>>q;
            vector<vector<int>>res;
         int startindex=0;
           int target=graph.size()-1;
            vector<int>v;
            v.push_back(startindex);
            q.push(v);
            while(!q.empty())
        {  int size=q.size();
         while(size-->0)
         {vector<int>temp=q.front();
                    q.pop();
                    if(temp.back()==target)
                            res.push_back(temp);
                    else
                    {
                        for(auto v:graph[temp.back()])
                        { vector<int>ans=temp;
                            ans.push_back(v);
                            q.push(ans);
                        }
                           
                    }
                            
            }
        }
            return res;
    }
};