//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends



int countRev (string s)
{
    // your code here
    if(s.size()%2!=0)return -1;
    else{
        stack<char>st;
        int c=0;
        int c2=0;
        for(int i=0;i<s.size();i++)
        {
            char ch=s[i];
            if(ch=='{')
            {
                st.push(ch);
                c2++;
            }
            else if(ch=='}'&&!st.empty()&&st.top()=='{'){
                st.pop();
                c2--;
                
            }
            else{
                c++;
            }
        }
        if(c%2!=0)
        c=(c/2)+1;
        else
        c=c/2;
        if(c2%2!=0)
        c2=(c2/2)+1;
        else
        c2=c2/2;
        return (c+c2);
    }
}