class Solution {
public:
     void solve(string s,vector<string>&ans,unordered_map<string,bool>&m,int removal)
     {
         if(m[s])
             return ;
         m[s]=true;
         if(removal==0)
         {
             int removal_need=find_removal(s);
             if(removal_need==0)
             {
                 ans.push_back(s);
             }
         }
         for(int i=0;i<s.length();i++)
         {
             string left=s.substr(0,i);
             string right=s.substr(i+1);
             string join=left+right;
             solve(join,ans,m,removal-1);
         }
     }
   int  find_removal(string s)
   { stack<char>st;
       for(int i=0;i<s.length();i++)
       {
           if(s[i]=='(')
               st.push(s[i]);
           else if(s[i]==')')
               {
                   if(st.size()!=0&&st.top()=='(')
                       st.pop();
                   else
                       st.push(')');
               }
       }
    return st.size();
   }
    vector<string> removeInvalidParentheses(string s) {
        unordered_map<string,bool>m;
        int min_removal=find_removal(s);
        vector<string>ans;
        solve(s,ans,m,min_removal);
        return ans;
        
        
    }
};