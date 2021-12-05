class Solution {
public:
    int rob(vector<int>& nums) {
       int length=nums.size();
       if(length==1)
       {
           return nums[0];
       }
       if(length==2)
       {
           return max(nums[0],nums[1]);
       }
       int pro[length];
       pro[0]=nums[0];
       pro[1]=max(nums[0],nums[1]);
       for(int i=2;i<length;i++)
       {
           pro[i]=max(pro[i-2]+nums[i],pro[i-1]);
       }
       return pro[length-1];
    }
};
