class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int bits[32] = {0};
        for(int i = 0; i < nums.size(); i++){
            int j = 0;

            while(nums[i]){
                bits[j] += nums[i] % 2;
                nums[i] /= 2;
                j++;
            }
        }
        int ans = 0;
        for(int i = 0; i < 32; i++){
            
            ans += (1 << i) *(bits[i] % 3);
        }
        return ans;
    }
};
