int min(int a,int b)
{
    if(a>b)
    {
        return b;
    }
    else
    {
        return a;
    }
}
int maxArea(int* height, int heightSize){
   int maxNum=0,num;
    int i=0,j=heightSize-1;
    if(height[i]>height[j])
    {maxNum=(j-i)*height[j];}
    else
    {
       maxNum=(j-i)*height[i]; 
    }
    while(i!=j)
    {
    if(height[i]<height[j])
    {
        i++;
        num=(j-i)*min(height[i],height[j]);
        
    }
    else{
        j--;
        num=(j-i)*min(height[i],height[j]);
    }
    if(num>maxNum)
        {
            maxNum=num;
        }
    }
    return maxNum;
}
