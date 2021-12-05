class Solution {
public:
    Solution(vector<int>& nums) {
         this->nums = nums;
    }
    
    vector<int> reset() {
          return this->nums;
    }
    
    vector<int> shuffle() {
           vector<int> result(nums.begin(),nums.end());
           int size=nums.size();
      
        for(int i=size;i;i--)
        {
            swap(result[random()%i],result[i-1]);
        }
        return result;


    }
    private:
    vector<int> nums;
};
