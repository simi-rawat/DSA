class Solution {
public:
    int numberOfSubstrings(string s) {
        int lastA = -1, lastB = -1, lastC = -1;
        int n = s.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') lastA = i;
            else if (s[i] == 'b') lastB = i;
            else lastC = i;

            if (lastA != -1 && lastB != -1 && lastC != -1) {
                int minLast = min({lastA, lastB, lastC});
                ans += minLast + 1;
            }
       }

       return ans;
    }
};