class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {

        unordered_map<int, int> mp;

        for(auto &x : reservedSeats) {
            mp[x[0]] |= (1 << x[1]);
        }

        long long ans = 2LL * n;

        // Masks for the three possible blocks
        int left   = (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5);
        int middle = (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7);
        int right  = (1 << 6) | (1 << 7) | (1 << 8) | (1 << 9);

        for(auto &p : mp) {

            int mask = p.second;

            // We initially counted this row as 2 groups
            ans -= 2;

            if((mask & left) == 0 && (mask & right) == 0) {
                // Both outer blocks available
                ans += 2;
            }
            else if((mask & left) == 0 ||
                    (mask & middle) == 0 ||
                    (mask & right) == 0) {
                // At least one block available
                ans += 1;
            }
        }

        return ans;
    }
};