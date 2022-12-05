class Solution {
public:
    bool isok(vector<vector<int>>& image,int color, int sr, int sc,int n,int m)
    {
        if(sr>=0&&sr<n&&sc>=0&&sc<m&&image[sr][sc]==color)
        {return true;}
        return false;
    }
   void f(vector<vector<int>>& image, int sr, int sc, int newcolor,int color,int n,int m)
    {
        image[sr][sc]=newcolor;
        if(isok(image,color,sr+1,sc,n,m))
        f(image,sr+1,sc,newcolor,color,n,m);
       if(isok(image,color,sr-1,sc,n,m))
        f(image,sr-1,sc,newcolor,color,n,m);
        if(isok(image,color,sr,sc+1,n,m))
        f(image,sr,sc+1,newcolor,color,n,m);
        if(isok(image,color,sr,sc-1,n,m))
        f(image,sr,sc-1,newcolor,color,n,m);
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newcolor)
    {
        int n=image.size();
            int m=image[0].size();
    int color=image[sr][sc];
   
    if(color==newcolor)
        return image;
      f(image,sr,sc,newcolor,color,n,m);   
        return image;
    }
};