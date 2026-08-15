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
    int numberOfSubarrays(vector<int>& nums, int k) {
        vector <int> ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i] %2==0){
                ans.push_back(0);
            }
            else{
                ans.push_back(1);
            }

        }
        int c1=countArray(ans,k);
        int c2=countArray(ans,k-1);
        return c1-c2;
        
    }
};