class SegmentTree {
public:
    int n;
    vector<int> tree;

    SegmentTree(const vector<int>& arr) {
        n = arr.size();
        if (n == 0) return;
        tree.assign(4 * n, 0);
        build(1, 0, n - 1, arr);
    }

    void build(int node, int l, int r, const vector<int>& arr) {
        if (l == r) {
            tree[node] = arr[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(node << 1, l, mid, arr);
        build(node << 1 | 1, mid + 1, r, arr);
        tree[node] = max(tree[node << 1], tree[node << 1 | 1]);
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return 0;
        if (ql <= l && r <= qr) return tree[node];
        int mid = (l + r) >> 1;
        return max(query(node << 1, l, mid, ql, qr),
                   query(node << 1 | 1, mid + 1, r, ql, qr));
    }

    int query(int l, int r) {
        if (n == 0 || l > r) return 0;
        return query(1, 0, n - 1, l, r);
    }
};

class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.size();

        int totalOnes = 0;
        for (char c : s)
            if (c == '1')
                totalOnes++;

        vector<int> blockLeft, blockRight, blockLen;

        for (int i = 0; i < n;) {
            if (s[i] == '1') {
                i++;
                continue;
            }
            int j = i;
            while (j < n && s[j] == '0') j++;
            blockLeft.push_back(i);
            blockRight.push_back(j - 1);
            blockLen.push_back(j - i);
            i = j;
        }

        int m = blockLen.size();

        if (m < 2) {
            return vector<int>(queries.size(), totalOnes);
        }

        vector<int> tmpSum;
        for (int i = 0; i + 1 < m; i++)
            tmpSum.push_back(blockLen[i] + blockLen[i + 1]);

        SegmentTree st(tmpSum);

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0], r = q[1];

            int i = lower_bound(blockRight.begin(), blockRight.end(), l) - blockRight.begin();
            int j = upper_bound(blockLeft.begin(), blockLeft.end(), r) - blockLeft.begin() - 1;

            if (i >= m || j < 0 || i >= j) {
                ans.push_back(totalOnes);
                continue;
            }

            int firstLen = blockRight[i] - max(blockLeft[i], l) + 1;
            int lastLen = min(blockRight[j], r) - blockLeft[j] + 1;

            int bestGain;

            if (i + 1 == j) {
                bestGain = firstLen + lastLen;
            } else {
                int val1 = firstLen + blockLen[i + 1];
                int val2 = blockLen[j - 1] + lastLen;
                int val3 = st.query(i + 1, j - 2);
                bestGain = max({val1, val2, val3});
            }

            ans.push_back(totalOnes + bestGain);
        }

        return ans;
    }
};