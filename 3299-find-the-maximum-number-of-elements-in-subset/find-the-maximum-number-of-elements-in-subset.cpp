class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long,int> cnt;
        for (int x : nums) cnt[x]++;

        int ans = 1;

        // Special case for 1
        if (cnt.count(1))
            ans = (cnt[1] & 1) ? cnt[1] : cnt[1] - 1;

        for (auto &[x, f] : cnt) {
            if (x == 1) continue;

            long long cur = x;
            int len = 0;

            while (true) {
                if (!cnt.count(cur)) {
                    len--;
                    break;
                }

                if (cnt[cur] == 1) {
                    len++;
                    break;
                }

                len += 2;

                if (cur > 31622) {   // sqrt(1e9)
                    len--;
                    break;
                }

                cur *= cur;
            }

            ans = max(ans, len);
        }

        return ans;
    }
};