   int climbStairs(int n) {
       if(n==1)
       {
           return 1;

       }
       if(n==2)
       {
           return 2;
       }
       int back[n];
       back[0]=1;
       back[1]=2;
       
       for(int i=2;i<n;i++)
       {
            back[i]=back[i-1]+back[i-2];
       }
       return back[n-1];
    

    }
