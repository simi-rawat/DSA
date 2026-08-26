class Solution {
public:
    const int MOD = 1e9 + 7;
    const int LOG = 18;

    vector<vector<int>> up;
    vector<int> depth;

    void dfs(int node, int parent, vector<vector<int>>& adj) {
        up[node][0] = parent;

        for(int j = 1; j < LOG; j++) {
            up[node][j] = up[up[node][j - 1]][j - 1];
        }

        for(int next : adj[node]) {
            if(next == parent)
                continue;

            depth[next] = depth[node] + 1;
            dfs(next, node, adj);
        }
    }

    int lca(int u, int v) {

        // Make u the deeper node
        if(depth[u] < depth[v])
            swap(u, v);

        // Bring u to the same depth as v
        int diff = depth[u] - depth[v];

        for(int j = 0; j < LOG; j++) {
            if(diff & (1 << j)) {
                u = up[u][j];
            }
        }

        // Already same node
        if(u == v)
            return u;

        // Move both upwards
        for(int j = LOG - 1; j >= 0; j--) {
            if(up[u][j] != up[v][j]) {
                u = up[u][j];
                v = up[v][j];
            }
        }

        return up[u][0];
    }

    vector<int> assignEdgeWeights(vector<vector<int>>& edges,
                                  vector<vector<int>>& queries) {

        int n = edges.size() + 1;

        vector<vector<int>> adj(n + 1);

        for(auto &e : edges) {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        up.assign(n + 1, vector<int>(LOG));
        depth.assign(n + 1, 0);

        // Root the tree at node 1
        dfs(1, 1, adj);

        // pow2[i] = 2^i % MOD
        vector<long long> pow2(n + 1, 1);

        for(int i = 1; i <= n; i++) {
            pow2[i] = (pow2[i - 1] * 2) % MOD;
        }

        vector<int> ans;

        for(auto &q : queries) {

            int u = q[0];
            int v = q[1];

            int L = lca(u, v);

            int dist = depth[u] + depth[v] - 2 * depth[L];

            if(dist == 0) {
                ans.push_back(0);
            }
            else {
                ans.push_back(pow2[dist - 1]);
            }
        }

        return ans;
    }
};