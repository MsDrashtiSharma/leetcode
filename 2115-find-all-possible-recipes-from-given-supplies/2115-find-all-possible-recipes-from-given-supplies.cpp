class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
         unordered_set<string>s;
        for(auto it:supplies)
            s.insert(it);
        int n=recipes.size();
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            q.push(i);
        }
        bool keeptracking=true;
       
         vector<bool>mark(n,false);
        while(keeptracking)
        {
            keeptracking=false;
            queue<int>pq;
           
        while(!q.empty())
        {    bool fl=true;                 //considering that all the indegrient are rthier in the list for particular recipe is not we will turn it into false like line 26
            int i=q.front();
             q.pop();
            for(int j=0;j<ingredients[i].size();j++)
            {  //check if it is in suppies
                if(s.find(ingredients[i][j])==s.end())
                {
                    fl=false;
                    break;
                }
            }
         if(fl==true)
         {
             s.insert(recipes[i]);
      //it is true bcoz one recipe is added and it has a chances to make another before recipe which is not prepared for better understanding solve the below commented example
             keeptracking=true;
             mark[i]=true;
         }
         else
         {
             pq.push(i);
         }
        }
            q=pq;
        }
        vector<string>ans;
        for(int i=0;i<n;i++)
        {
            if(mark[i]==true)
                ans.push_back(recipes[i]);
        }
        return ans;
    }
};