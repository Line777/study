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
int maxCount(int m, int n, int** ops, int opsSize, int* opsColSize){
 int minX = m;
        int minY = n;
        for (int i = 0; i < opsSize; i++) {
            minX = min(ops[i][0], minX);
            minY = min(ops[i][1], minY);
        }
        return minX * minY;
}
