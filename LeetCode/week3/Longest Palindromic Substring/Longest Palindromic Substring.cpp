class Solution {
public:
    string longestPalindrome(string s) {
            int length=s.length();
            int max=0,head,tail;
            for(int k=0;k<length;k++)
            {   int i=k;
                int j=k;
            while(i>=0&&j<length)
            {
                    if(s[i]==s[j])
                    {
                        if(j-i+1>max)
                        {
                            max=j-i+1;
                            head=i;
                            tail=j;
                        }
                        i--;
                        j++;
                    }  
                    else
                    {
                        break;
                    }
            }
            }
             for(int k=0;k<length-1;k++)
            {   int i=k;
                int j=k+1;
            while(i>=0&&j<length)
            {
                    if(s[i]==s[j])
                    {
                        if(j-i+1>max)
                        {
                            max=j-i+1;
                            head=i;
                            tail=j;
                        }
                        i--;
                        j++;
                    }  
                    else
                    {
                        break;
                    }
            }
            }
            string ans =s.substr(head,tail-head+1);
            return ans;
    }
};
