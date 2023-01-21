//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            //code here.
           //code here.

            vector<int> ans1;

            unordered_map<int,bool> mp1;

            unordered_map<int,bool> mp2;

            

            for(int i=0;i<n1;i++)

            {

                mp1[A[i]]=true;

            }

            for(int i=0;i<n2;i++)

            {

                if(mp1.find(B[i])!=mp1.end())

                {

                    ans1.push_back(B[i]);

                }

            }

            vector<int> ans2;

            for(int i=0;i<ans1.size();i++)

            {

                mp2[ans1[i]]=true;

            }

            

            for(int i=0;i<n3;i++)

            {

                if(mp2.find(C[i])!=mp2.end())

                {

                    ans2.push_back(C[i]);

                }

            }

            

          unordered_set<int> st;

          for(int i=0;i<ans2.size();i++)

          {

              st.insert(ans2[i]);

          }

          vector<int> ansfin;

          for(auto it: st)

          {

              ansfin.push_back(it);

          }

             sort(ansfin.begin(),ansfin.end());

             return ansfin;

        }

};

//{ Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; 
        cin >> n1 >> n2 >> n3;
        int A[n1];
        int B[n2];
        int C[n3];
        
        for (int i = 0; i < n1; i++) cin >> A[i];
        for (int i = 0; i < n2; i++) cin >> B[i];
        for (int i = 0; i < n3; i++) cin >> C[i];
        
        Solution ob;
        
        vector <int> res = ob.commonElements (A, B, C, n1, n2, n3);
        if (res.size () == 0) 
            cout << -1;
        for (int i = 0; i < res.size (); i++) 
            cout << res[i] << " "; 
        cout << endl;
    }
}
// } Driver Code Ends