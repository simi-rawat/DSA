class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n=nums.size(),ans=0;
        for(int i=0;i<n;i++){
            int s=0;
            for(int j=i;j<n;j++){
                s+=nums[j]==target?1:-1;
                ans+=s>0;
            }
        }
        return ans;
    }
};