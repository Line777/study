int* singleNumber(int* nums, int numsSize, int* returnSize){
    int *res = (int *)calloc(2, sizeof(int));
   for(int i=0;i<numsSize;i++)
   {
       for(int j=i+1;j<numsSize;j++)
       {
           if(nums[i]>nums[j])
           {
               int m=nums[i];
               nums[i]=nums[j];
               nums[j]=m;
           }
       }
   }
   int k=0,a,b;
  for(int i=0;i<numsSize-1;i++)
  {
      
  
      if(nums[i]==nums[i+1])
      {
          i++;
      }
      else
      {
          
           res[k]=nums[i];
           k++;
      }
  }
 if(nums[numsSize-1]!=nums[numsSize-2])
  {
      res[k]=nums[numsSize-1];
  }

  return res;
  

    
}
