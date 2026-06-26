class Solution {
public:
    struct BIT {
        vector<int> bit;
        BIT(int n):bit(n+1){}
        void add(int i){
            for(;i<bit.size();i+=i&-i) bit[i]++;
        }
        int sum(int i){
            int s=0;
            for(;i;i-=i&-i) s+=bit[i];
            return s;
        }
    };

    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> pre(n+1);

        for(int i=0;i<n;i++)
            pre[i+1]=pre[i]+(nums[i]==target?1:-1);

        vector<int> v=pre;
        sort(v.begin(),v.end());
        v.erase(unique(v.begin(),v.end()),v.end());

        BIT ft(v.size()+2);
        long long ans=0;

        for(int x:pre){
            int id=lower_bound(v.begin(),v.end(),x)-v.begin()+1;
            ans+=ft.sum(id-1);
            ft.add(id);
        }

        return ans;
    }
};