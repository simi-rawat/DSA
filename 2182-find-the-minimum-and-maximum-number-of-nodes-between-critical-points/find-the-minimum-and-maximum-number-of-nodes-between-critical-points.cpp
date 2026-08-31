class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int first = -1;
        int prev = -1;        
        int minDist = INT_MAX;
        int maxDist = -1;

        ListNode* prevNode = head;
        ListNode* curr = head->next;
        int pos = 1;

        while (curr != nullptr && curr->next != nullptr) {
            ListNode* nextNode = curr->next;
            bool isCritical =
                (curr->val > prevNode->val && curr->val > nextNode->val) ||
                (curr->val < prevNode->val && curr->val < nextNode->val);

            if (isCritical) {
                if (first == -1) {
                    first = pos;
                } else {

                    minDist = min(minDist, pos - prev);
                    maxDist = pos - first;
                }

                prev = pos;
            }

            prevNode = curr;
            curr = nextNode;
            pos++;
        }

        if (prev == first) {
            return {-1, -1};
        }

        return {minDist, maxDist};
    }
};