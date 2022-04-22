class Solution {
public:
    
   
    bool checkpossi(string &s1,string &s2)
    {  
        if(s1.size()!=s2.size()+1)return false;
        int first=0;
        int second=0;
       while(first<s1.size())
       {
           if(s1[first]==s2[second])
           {
               first++;
               second++;
           }
           else
           {
               first++;
           }
       }
        if(first==s1.size()&&second==s2.size())return true;
        else return false;
    }
  
   
    static bool comp(string &a, string &b){
        if(a.size() < b.size()){
            return true;
        }
        return false;
    }

    int longestStrChain(vector<string>& words) 
    {
             sort(words.begin(),words.end(),comp);

        int n=words.size();
        vector<int>dp(n,1);
        int maxi=1;
        for(int i=0;i<n;i++)
        {
            for(int prev=0;prev<i;prev++)
            {
                if(checkpossi(words[i],words[prev]) && 1+dp[prev]>dp[i])
                    dp[i]=dp[prev]+1;
                
            }
            if(dp[i]>maxi)
            {
                maxi=dp[i];
            }
        }
    return maxi;
    }
};