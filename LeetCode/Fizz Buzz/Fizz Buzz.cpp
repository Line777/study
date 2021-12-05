class Solution {
public:
    vector<string> fizzBuzz(int n) {
   vector<string> result;
         for(int i=0;i<n;i++)
         {
             int num=i+1;
             if(num%3==0&&num%5!=0)
             {
                 result.push_back("Fizz");
             }
             if(num%5==0&&num%3!=0)
             {
                 result.push_back("Buzz");
             }
             if(num%5==0&&num%3==0)
             {
                 result.push_back("FizzBuzz");
             }
             if(num%5!=0&&num%3!=0)
             {
                 string a=to_string(num);
                 result.push_back(a);
             }
         }
         return result;
    }
};
