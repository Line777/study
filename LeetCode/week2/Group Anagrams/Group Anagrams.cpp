class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
              unordered_map<string,vector<string>> str;
              int length=strs.size();
              for(int i=0;i<length;i++)
              {
                  string k=strs[i];
                  sort(k.begin(),k.end());
                  str[k].push_back(strs[i]);
              }
              vector<vector<string>> result;
              for(auto i=str.begin();i!=str.end();i++)
              {
                  result.push_back(i->second);
              }
              return result;
    }
};
