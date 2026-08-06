class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxlen=0 ;
        int left=0;
        int zero = 0;
        for(int right = 0;right<nums.size();right++){
            if(nums[right]==0){
                zero++;
            }
            while(zero>k){
                if(nums[left] == 0)
                    zero--;
                left++;
            }
            maxlen=max(maxlen,right-left+1);
        }
        return maxlen;
    }
};