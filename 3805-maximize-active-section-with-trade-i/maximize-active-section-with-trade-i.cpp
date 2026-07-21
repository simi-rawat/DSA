class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        int active = 0;
        for (char c : s)
            if (c == '1') active++;

        string t = "1" + s + "1";
        int m = t.size();

        vector<pair<char,int>> runs;

        // Run-length encoding
        for (int i = 0; i < m;) {
            int j = i;
            while (j < m && t[j] == t[i]) j++;
            runs.push_back({t[i], j - i});
            i = j;
        }

        int ans = active;

        // Pattern: 0-run, 1-run, 0-run
        for (int i = 1; i + 1 < runs.size(); i++) {
            if (runs[i].first != '1') continue;
            if (runs[i - 1].first != '0') continue;
            if (runs[i + 1].first != '0') continue;

            int removed = runs[i].second;
            int mergedZero = runs[i - 1].second + removed + runs[i + 1].second;

            ans = max(ans, active - removed + mergedZero);
        }

        return ans;
    }
};