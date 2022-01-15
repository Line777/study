class Solution {
public:
    int maxProfit(vector<int>& prices) {
             int size=prices.size();
             if(size==0)
             {
                 return 0;
             }
             for(int i=size-1;i>0;i--)
             {     
               
                   
                    prices[i]=prices[i]-prices[i-1];
             }
             prices[0]=0;
             vector<int> ans;
             ans.push_back(0);
             for(int i=1;i<size;i++)
             {
                 int pos=ans[i-1]+prices[i];
                 int pre=prices[i]; 
                 if(pre>pos )
                 {
                     pos=pre;
                 }
                 ans.push_back(pos);
             }
             int max=0;
             for(int i=0;i<ans.size();i++)
             {
                 if(ans[i]>max)
                 {
                     max=ans[i];
                 }
             }
             return max;
    }
};
