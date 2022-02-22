// { Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
//User function Template for C++

class Solution 
{
    bool check(int i, int j, int N, int M, vector<vector<int>> &hospital)
    {
        if(i >= 0 and i < N and j >= 0 and j < M and hospital[i][j] == 1)
        {
            return true;
        }
        
        return false;
    }
    
    public:
    int helpaterp(vector<vector<int>> hospital)
    {
        int N = hospital.size();
        int M = hospital[0].size();
        
        queue<pair<int, int>> q;
        
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < M; j++)
            {
                if(hospital[i][j] == 2)
                {
                    q.push({i, j});
                }
            }
        }
        
        int timer = -1;
        
        while(!q.empty())
        {
            int size = q.size();
            
            while(size--)
            {    
                int currX = q.front().first;
                int currY = q.front().second;
                
                if(check(currX - 1, currY, N, M, hospital))
                {
                    q.push({currX - 1, currY});
                    
                    hospital[currX - 1][currY] = 2;
                }
                
                if(check(currX, currY + 1, N, M, hospital))
                {
                    q.push({currX, currY + 1});
                    
                    hospital[currX][currY + 1] = 2;
                }
                
                if(check(currX + 1, currY, N, M, hospital))
                {
                    q.push({currX + 1, currY});
                    
                    hospital[currX + 1][currY] = 2;
                }
                
                if(check(currX, currY - 1, N, M, hospital))
                {
                    q.push({currX, currY - 1});
                    
                    hospital[currX][currY - 1] = 2;
                }
                
               q.pop();
            }
            
            timer++;
        }
        
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < M; j++)
            {
                if(hospital[i][j] == 1)
                {
                    return -1;
                }
            }
        }
        
        return timer;
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R;int C;
        
        cin>>R>>C;
        vector<vector<int>> hospital;
        int i,j;
        for(i=0;i<R;i++)
         {   vector<int> temp;
             for(j=0;j<C;j++)
            {
                int k;
                cin>>k;
                temp.push_back(k);
            }
            hospital.push_back(temp);
         }
        
        Solution ob;
        int ans = ob.helpaterp(hospital);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends