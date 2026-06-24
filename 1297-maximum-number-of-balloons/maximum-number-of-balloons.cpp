class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> cnt(128);

        for(char c : text)
            cnt[c]++;

        return min({
            cnt['b'],
            cnt['a'],
            cnt['l']/2,
            cnt['o']/2,
            cnt['n']
        });
    }
};