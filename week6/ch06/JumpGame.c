bool canJump(int* nums, int numsSize){
    int maxPos=nums[0]+1;
    if(numsSize==1)
    {
        return true;
    }
    for(int i=1;i<numsSize;i++)
    {
        if(maxPos>=numsSize)
        {
            return true;
        }
        if(i+1>maxPos)
        {
            return false;
        }
        if(i+1+nums[i]>maxPos)
        {
            maxPos=1+i+nums[i];
        }

    }
    return false;
}
