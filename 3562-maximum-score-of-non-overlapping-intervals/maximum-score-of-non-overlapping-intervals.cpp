class Solution {
public:

    struct Node {
        long long score;
        vector<int> indices;
    };

    // Returns true if a is better than b
    bool better(const Node& a, const Node& b) {

        // Higher score is better
        if (a.score != b.score)
            return a.score > b.score;

        // If score is same, lexicographically smaller is better
        return a.indices < b.indices;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        int n = intervals.size();


        vector<vector<long long>> a;

        for (int i = 0; i < n; i++) {
            a.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        sort(a.begin(), a.end());

        vector<long long> starts(n);

        for (int i = 0; i < n; i++) {
            starts[i] = a[i][0];
        }

        vector<int> next(n);

        for (int i = 0; i < n; i++) {

            next[i] =
                upper_bound(starts.begin(),
                            starts.end(),
                            a[i][1])
                - starts.begin();
        }

        vector<vector<Node>> dp(n + 1, vector<Node>(5));


        for (int k = 0; k <= 4; k++) {
            dp[n][k] = {0, {}};
        }

        for (int i = n - 1; i >= 0; i--) {

            for (int k = 1; k <= 4; k++) {

                Node skip = dp[i + 1][k];

                Node take = dp[next[i]][k - 1];

                take.score += a[i][2];

                take.indices.push_back((int)a[i][3]);

                sort(take.indices.begin(), take.indices.end());

                if (better(take, skip))
                    dp[i][k] = take;
                else
                    dp[i][k] = skip;
            }
        }

        return dp[0][4].indices;
    }
};