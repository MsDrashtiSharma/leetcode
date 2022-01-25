class Solution {
public:
      bool  valid(int i,int j,int n,int m,int color,vector<vector<int>>& image)
        {
                if(i>=0&&i<n&&j>=0&&j<m&&image[i][j]==color)
                        return true;
                return false;
        }
      void  floodFillcheck(vector<vector<int>>& image,int sr,int sc, int newcolor,int color,int n,int m){
               image[sr][sc]=newcolor;
                if(valid(sr+1,sc,n,m,color,image))
                floodFillcheck( image, sr+1, sc, newcolor, color, n,m)  ;
                if(valid(sr-1,sc,n,m,color,image))
                floodFillcheck( image, sr-1, sc, newcolor, color, n,m)  ;
                if(valid(sr,sc+1,n,m,color,image))
                floodFillcheck( image, sr, sc+1, newcolor, color, n,m)  ;
                if(valid(sr,sc-1,n,m,color,image))
                floodFillcheck( image, sr, sc-1, newcolor, color, n,m)  ;
                
                
        }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newcolor) 
    {
        int n=image.size();
            int m=image[0].size();
            int color=image[sr][sc];
            if(color==newcolor)
                    return image;
        floodFillcheck(image,sr,sc, newcolor,color,n,m);
            return image;
            
    }
};