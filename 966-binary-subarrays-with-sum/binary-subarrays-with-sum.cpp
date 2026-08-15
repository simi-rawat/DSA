class Solution {
public:
    int countArray(vector<int>& nums, int goal){
        if(goal<0) return 0;
        int l=0,r=0,sum=0,count=0;
        while(r<nums.size()){
            sum+=nums[r];
            while(sum>goal){
                sum-=nums[l];
                l++;
            }
            count=count+(r-l+1);
            r=r+1;
        }
        return count;

    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        if(goal<0) return 0;
        int c1=countArray(nums,goal);
        int c2=countArray(nums,goal-1);
        return c1-c2;
        

        
    }
};