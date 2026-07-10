class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                     vector<vector<int>>& queries) {

        // value, original index
        vector<pair<int,int>> arr;
        for (int i = 0; i < n; i++)
            arr.push_back({nums[i], i});

        sort(arr.begin(), arr.end());

        // pos[originalIndex] = position in sorted array
        vector<int> pos(n);
        for (int i = 0; i < n; i++)
            pos[arr[i].second] = i;

        // left[i] = leftmost index reachable in one jump
        vector<int> left(n);
        left[0] = 0;

        int l = 0;
        for (int r = 1; r < n; r++) {
            while (arr[r].first - arr[l].first > maxDiff)
                l++;
            left[r] = l;
        }

        int LOG = 0;
        while ((1 << LOG) <= n)
            LOG++;

        vector<vector<int>> up(LOG, vector<int>(n));

        // 2^0 jump
        for (int i = 0; i < n; i++)
            up[0][i] = left[i];

        // Binary lifting table
        for (int k = 1; k < LOG; k++) {
            for (int i = 0; i < n; i++) {
                up[k][i] = up[k - 1][up[k - 1][i]];
            }
        }

        vector<int> ans;

        for (auto &q : queries) {
            int u = pos[q[0]];
            int v = pos[q[1]];

            if (u == v) {
                ans.push_back(0);
                continue;
            }

            if (u > v)
                swap(u, v);

            int cur = v;
            int dist = 0;

            for (int k = LOG - 1; k >= 0; k--) {
                if (up[k][cur] > u) {
                    cur = up[k][cur];
                    dist += (1 << k);
                }
            }

            if (left[cur] <= u)
                ans.push_back(dist + 1);
            else
                ans.push_back(-1);
        }

        return ans;
    }
};