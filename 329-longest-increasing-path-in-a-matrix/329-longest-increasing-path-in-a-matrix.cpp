class Solution {
public:
    int dp_matrix[201][201];
    int dfs(int j,int i,vector<vector<int>>& matrix, int prev)
    {   
        if(i<0||j<0||i==matrix.size()||j==matrix[0].size()||prev>=matrix[i][j])
            return 0;
        if(dp_matrix[i][j])   //this step is ...so that we don't move to again to the matrix cell in which longest incesrsing apth distance is already calculated bcoz other the code will give tle
            return dp_matrix[i][j];
      int a=dfs(j+1,i,matrix,matrix[i][j]);
         int b=dfs(j-1,i,matrix,matrix[i][j]);
       int c= dfs(j,i+1,matrix,matrix[i][j]);
         int d=dfs(j,i-1,matrix,matrix[i][j]);
        return dp_matrix[i][j]=max({a,b,c,d})+1;
    
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int maxval=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                maxval=max(maxval,dfs(j,i,matrix,-1));
            }
            
        }
        return maxval;
    }
};