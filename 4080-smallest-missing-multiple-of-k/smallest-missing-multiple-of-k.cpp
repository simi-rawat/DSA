class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {

        unordered_set<int> st;

        for(int x : nums) {
            st.insert(x);
        }

        for(int x = k; ; x += k) {

            if(st.find(x) == st.end()) {
                return x;
            }
        }

        return -1;
    }
};