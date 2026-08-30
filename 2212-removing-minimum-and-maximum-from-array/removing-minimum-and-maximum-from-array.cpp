
class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int minIdx = 0, maxIdx = 0;

        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[minIdx])
                minIdx = i;

            if (nums[i] > nums[maxIdx])
                maxIdx = i;
        }

        if (minIdx > maxIdx)
            swap(minIdx, maxIdx);

        int fromFront = maxIdx + 1;
        int fromBack = n - minIdx;
        int fromBoth = (minIdx + 1) + (n - maxIdx);

        return min({fromFront, fromBack, fromBoth});
    }
};

