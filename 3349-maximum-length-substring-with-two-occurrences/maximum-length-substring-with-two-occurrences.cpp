class Solution {
public:
    int maximumLengthSubstring(string s) {

        int l = 0;
        int ans = 0;

        int freq[26] = {0};

        for(int r = 0; r < s.size(); r++) {

            freq[s[r] - 'a']++;
            while(freq[s[r] - 'a'] > 2) {
                freq[s[l] - 'a']--;
                l++;
            }
            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};