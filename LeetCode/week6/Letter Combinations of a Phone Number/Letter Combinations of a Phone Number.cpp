class Solution {
public:
    vector<string> letterCombinations(string digits) {
          vector<string>  ans;
          vector<string> board={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
          queue<string> dfs;
          queue<char> digit;
          int length=digits.length();
          if(length==0)
          {
              return ans;
          }
          for(int i=0;i<length;i++)
          {
              digit.push(digits[i]);
          }
          while(!digit.empty())
          {  
              int lengthDfs=dfs.size();
              char a=digit.front();
              digit.pop();
                string now=board[a-'0'];
                int lengthStr=now.length();
                if(lengthDfs==0)
                {
                    for(int i=0;i<lengthStr;i++)
                {
                    string z="";
                    z=z+now[i];
                     dfs.push(z);   
                }
                }
              for(int j=0;j<lengthDfs;j++)
              {
                  string k=dfs.front();
                for(int i=0;i<lengthStr;i++)
                {
                    string n=k+now[i];
                     dfs.push(n);   
                }
             
                dfs.pop();
              }
          }    
          while(!dfs.empty()) 
          {
              ans.push_back(dfs.front());
              dfs.pop();
          }   
          return ans;
    }
};
