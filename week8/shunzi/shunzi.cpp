class Solution {
public:
    bool isStraight(vector<int>& nums) {
          short hash=0;
        char k=0,max=14,min=0;
        for(char n:nums){
            if(n){
                if(hash>>n&1) return false;
                else hash|=1<<n;
            }
            else k++;
        }
        while(--max) if(hash>>max) break;
        while(++min) if(hash>>min&1) break;
        return max-min-k<5;

    }
};
