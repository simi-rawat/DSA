class Solution {
public:
    bool check(long long mid,
               vector<vector<pair<int,int>>>& adj,
               vector<int>& topo,
               vector<bool>& online,
               long long k,
               int n) {

        const long long INF = 4e18;
        vector<long long> dist(n, INF);
        dist[0] = 0;

        for (int u : topo) {
            if (dist[u] == INF) continue;

            for (auto &[v, w] : adj[u]) {
                if (w < mid) continue;                    // edge too small
                if (v != n - 1 && !online[v]) continue;  // offline intermediate

                dist[v] = min(dist[v], dist[u] + w);
            }
        }

        return dist[n - 1] <= k;
    }

    int findMaxPathScore(vector<vector<int>>& edges,
                         vector<bool>& online,
                         long long k) {

        int n = online.size();

        vector<vector<pair<int,int>>> adj(n);
        vector<int> indegree(n, 0);

        long long hi = 0;

        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
            indegree[v]++;
            hi = max(hi, 1LL * w);
        }

        // Topological Sort
        queue<int> q;
        for (int i = 0; i < n; i++)
            if (indegree[i] == 0)
                q.push(i);

        vector<int> topo;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            topo.push_back(u);

            for (auto &[v, w] : adj[u]) {
                if (--indegree[v] == 0)
                    q.push(v);
            }
        }

        long long lo = 0, ans = -1;

        while (lo <= hi) {
            long long mid = lo + (hi - lo) / 2;

            if (check(mid, adj, topo, online, k, n)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return (int)ans;
    }
};