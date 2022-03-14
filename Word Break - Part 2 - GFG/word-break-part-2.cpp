// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public: void find(int pos, vector<string>&v,string str,set<string>&se,int n,string s)
{
    if(pos==s.length())
    {v.push_back(str);
    return; 
    }
    string out="";
    for(int i=pos;i<s.length();i++)
    { out=out+s[i];
        if(se.find(out)!=se.end())
        {
            if(str.length()==0)
            {
                find(i+1,v,str+out,se,n,s);
            }
            else
            find(i+1,v,str+" "+out,se,n,s);
        }
    }
}

    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        // code here
        vector<string>v;
        set<string>se;
        for(auto i:dict)
        {
        se.insert(i);
        }
        string str="";
        find(0,v,str,se,n,s);
        return v;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends