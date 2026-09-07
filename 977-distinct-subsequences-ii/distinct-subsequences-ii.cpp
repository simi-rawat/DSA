class Solution {
public:
    int distinctSubseqII(string s) {
        const long long MOD = 1e9 + 7;

        vector<long long> dp(26, 0);

        long long total = 0;

        for (char c : s) {
            int x = c - 'a';
            long long newCount = (total + 1) % MOD;
            total = (total - dp[x] + newCount) % MOD;

            if (total < 0)
                total += MOD;

            dp[x] = newCount;
        }

        return total;
    }
};