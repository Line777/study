int maxProfit(int* prices, int pricesSize){
 int n=0;
        for(int i=1;i<pricesSize;i++)
        {
            if(prices[i]>prices[i-1])
            {
                n=n+prices[i]-prices[i-1];
            }
        }
        return n;

}
