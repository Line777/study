class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
         
         vector<vector<int>> ans;
         int sum=0;
         for(int i=1;i<target;i++)
         {
             for(int j=i;j<target;j++)
             {
                 sum=sum+j;
                 if(sum==target)
                 {
                     vector<int> now;
                     for(int k=i;k<=j;k++)
                     {
                         now.push_back(k);
                     }
                     ans.push_back(now);
                     sum=0;
                     now.clear();
                     break;
                 }
                 if(sum>target)
                 {
                     sum=0;
                     break;
                 }
             }
         }
         return ans;
    }
};
