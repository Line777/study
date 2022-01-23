class Solution {
public:
    string minNumber(vector<int>& nums) {
       vector<string> strs;
       for(int i = 0; i < nums.size(); i++)
       {
            strs.push_back(to_string(nums[i]));
        }
        int length=strs.size();
       for(int i=0;i<length;i++)
       {
           for(int j=0;j<length;j++)
           {
               if(strs[i]+strs[j]<strs[j]+strs[i])
               {
                   swap(strs[j],strs[i]);
               }
           }
       }
       string ans="";
       for(int i=0;i<length;i++)
       {
            ans=ans+strs[i];
       }
       return ans;
    }
};
