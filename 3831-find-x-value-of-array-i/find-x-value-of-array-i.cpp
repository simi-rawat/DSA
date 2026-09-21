class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);
        vector<long long> dp(k, 0);

        for (int x : nums) {
            int val = x % k;

            vector<long long> ndp(k, 0);

            ndp[val]++;

            for (int r = 0; r < k; r++) {
                int newR = (r * val) % k;
                ndp[newR] += dp[r];
            }
            for (int r = 0; r < k; r++) {
                ans[r] += ndp[r];
            }

            dp = ndp;
        }

        return ans;
    }
};