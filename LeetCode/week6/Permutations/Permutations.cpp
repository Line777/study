class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
       vector<vector<int>> ans;
       int length=nums.size();
       int n=0;
       int now=0;
       vector<int> nowans;
       backtrace(ans,nums,length,n,nowans);
       return ans;
    }
    void backtrace(vector<vector<int>> &ans,vector<int> &nums,int length,int n,vector<int> &nowans)
    {
        if(n==length)
        {
             ans.push_back(nowans);
        }
        else
        {
             for(int i=0;i<length;i++ )
             { 
                 int flag=0;
                for(int k=0;k<nowans.size();k++)
                {
                        if(nums[i]==nowans[k])
                        {
                            flag=1;
                        }
                }
                if(flag==0)
                {
                 nowans.push_back(nums[i]);
                 backtrace(ans,nums,length,n+1,nowans);
                 nowans.pop_back();
                }
             }
        }
    }
};
