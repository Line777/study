int* sortArray(int* nums, int numsSize, int* returnSize){
int d, i, j, temp;                          //d为步长
    *returnSize = numsSize;

    for(d = numsSize/2; d >= 1; d = d/2){
        for(i = d; i < numsSize; ++i){
            if(nums[i] < nums[i-d]){
                temp = nums[i];
                for(j = i-d; j>=0 && temp<nums[j]; j-=d)
                    nums[j+d] = nums[j];
                nums[j+d] = temp;
            }
        }
    }

    return nums;

}
