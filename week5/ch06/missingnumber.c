int missingNumber(int* nums, int numsSize){
     for(int i=0;i<numsSize;i++)
     {
         for(int j=i;j<numsSize;j++)
         {
              if(nums[i]>nums[j])
              {
                  int m=nums[i];
                  nums[i]=nums[j];
                  nums[j]=m;
              }
         }
     }
     int number=0;
     for(int i=0;i<numsSize;i++)
     {
         if(nums[i]!=number)
         {
             return number;
         }
         number++;
     }
     return number;
}
