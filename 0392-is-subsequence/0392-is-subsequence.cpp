class Solution {
public:
    bool f(int i,int j, string &s,string &t)
    {    
        if(i==s.size())
        {
            return true;
        }
        if(j==t.size())
        {
            return false;
        }
        if(s[i]==t[j])
        {
            i++;
            j++;
            return f(i,j,s,t);
        }
     
           return  f(i,j+1,s,t);
        
    }
    bool isSubsequence(string s, string t) {
        return f(0,0,s,t);
    }
};