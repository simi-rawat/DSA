class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> ans;
        int n= nums.size();
        for(int i=nums[0];i<nums[n-1];i++){
            ans.push_back(i);            
        }
        for(int i= 0;i<ans.size();i++){
            for(int j=0;j<nums.size();j++){
                if(ans[i]==nums[j]){
                    ans.erase(remove(ans.begin(), ans.end(), nums[j]), ans.end());
                }
            }
        }
        return ans;
        
    }
};