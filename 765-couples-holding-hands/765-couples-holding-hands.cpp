class Solution {
public:
    map<int,int>m;
/*    void swap(vector<int>& row,int i,int j)
    {
        int temp=row[i];
        row[i]=row[j];
        row[j]=temp;
        m[row[i]]=i;
        m[row[j]]=j;
    }*/
    int minSwapsCouples(vector<int>& row) {
        int swaps=0;
        for(int i=0;i<row.size();i++)
            m[row[i]]=i;
        for(int i=0;i<row.size()-1;i+=2)
        {
            int first=row[i];
            int second=first^1;
            if(row[i+1]!=second)
            {
                swaps++;
                int j=m[second];
                swap(row[j],row[i+1]);
              // swap(row,i+1,m[second]);
                 m[row[i]]=i;
                 m[row[j]]=j;
            }
        }
        return swaps;
        
        
    }
};