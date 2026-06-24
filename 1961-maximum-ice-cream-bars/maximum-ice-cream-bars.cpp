class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        vector<int> cnt(100001);

        for (int c : costs)
            cnt[c]++;

        int ans = 0;

        for (int price = 1; price <= 100000 && coins >= price; price++) {
            int take = min(cnt[price], coins / price);

            ans += take;
            coins -= take * price;
        }

        return ans;
    }
};