class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int m=nums.size(),x,position[m];
        for(int i=0;i<m;i++)
        {
           x=(i+k)%m;
           position[x]=nums[i];
        }
        for(int y=0;y<m;y++)
        {
            nums[y]=position[y];
        }
        
    }
};
