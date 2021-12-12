class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
          int m=matrix.size();
           int n=matrix[0].size();
           int rows[m],cols[n];
           for(int i=0;i<m;i++)
           {
               rows[i]=0;
           }
             for(int i=0;i<n;i++)
           {
               cols[i]=0;
           }
           for(int i=0;i<m;i++)
           {
               for(int j=0;j<n;j++)
               {
                   if(matrix[i][j]==0)
                   {
                      rows[i]=1;
                       cols[j]=1;
                   }
               }
           }
         for(int i=0;i<m;i++)
         {
             for(int j=0;j<n;j++)
             {
                 if(rows[i]==1||cols[j]==1)
                 {
                     matrix[i][j]=0;
                 }
                
             }
         }
    }
    
};
