class Solution {
public:

    long long gcd(long long a, long long b) {
        while(b) {
            long long temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

    long long lcm(long long a, long long b) {
        return a / gcd(a, b) * b;
    }

    long long countNumbers(vector<int>& coins, long long x) {

        int n = coins.size();
        long long ans = 0;

        // Try every subset of coins
        for(int mask = 1; mask < (1 << n); mask++) {

            long long L = 1;
            int bits = 0;
            bool tooBig = false;

            for(int i = 0; i < n; i++) {

                if(mask & (1 << i)) {

                    bits++;

                    L = lcm(L, coins[i]);

                    if(L > x) {
                        tooBig = true;
                        break;
                    }
                }
            }

            if(tooBig)
                continue;

            long long cnt = x / L;


            if(bits % 2 == 1)
                ans += cnt;
            else
                ans -= cnt;
        }

        return ans;
    }

    long long findKthSmallest(vector<int>& coins, int k) {

        long long low = 1;
        int mn = *min_element(coins.begin(), coins.end());

        long long high = 1LL * mn * k;

        while(low < high) {

            long long mid = low + (high - low) / 2;

            if(countNumbers(coins, mid) >= k) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};