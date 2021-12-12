class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       vector<vector<int>> result;
       int length=nums.size();
       sort(nums.begin(), nums.end());   
       for(int i=0;i<length-2;i++)
       {
           if(i>0&&nums[i]==nums[i-1])
           {
               continue;
           }
           int n=length-1,target=-nums[i];
           for(int m=i+1;m<length;m++)
           {
                 if (m > i + 1 && nums[m] == nums[m - 1]) {
                    continue;
                }

          
            while (m < n && nums[m] + nums[n] > target)
            {
                --n;
            }
            if(m==n)
            {
                break;
            }
            if(nums[m] + nums[n] == target) {
                    result.push_back({nums[i], nums[m], nums[n]});
                }

           }
       
       }
       return result;

    }
};
