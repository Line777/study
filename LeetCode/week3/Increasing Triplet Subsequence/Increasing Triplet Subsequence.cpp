class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int length=nums.size();
        int min=INT_MAX,mid=INT_MAX;
         for(int num:nums)
         {
             if(num>min&&num>mid)
             {
                 return true;
             }
             if(num<min)
             {
                 min=num;
          
             }
             else
             {
                 if(num>min&&num<mid)
                 {
                     mid=num;
                 }
             }
         }
         
        return false;
    }
};
