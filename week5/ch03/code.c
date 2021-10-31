int majorityElement(int* nums, int numsSize){

int res = 0, count = 0;
        for (int i = 0; i < numsSize; i++)
         {
            if (count == 0) {
                res = nums[i];
                count++;
            }
            else {
                if (res == nums[i]) count++;
                else count--;
            }
        }
        return res;
    }
