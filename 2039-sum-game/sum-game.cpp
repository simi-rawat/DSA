class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int sumL = 0, sumR = 0;
        int qL = 0, qR = 0;

        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?') qL++;
            else sumL += num[i] - '0';
        }

        for (int i = n / 2; i < n; i++) {
            if (num[i] == '?') qR++;
            else sumR += num[i] - '0';
        }

        int totalQ = qL + qR;

        if (totalQ % 2 == 1)
            return true;

        return 2 * (sumL - sumR) != 9 * (qR - qL);
    }
};