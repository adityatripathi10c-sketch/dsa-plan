class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // 🛑 Base cases: no work needed if list is empty or k == 1
        if (head == nullptr || k == 1) {
            return head;
        }

        // 🛡️ Dummy node sitting right before the head
        ListNode dummy(0, head);
        ListNode* prevGroupTail = &dummy;

        while (true) {
            // 1. 🔍 Check if at least k nodes remain
            ListNode* kth = prevGroupTail;
            for (int i = 0; i < k && kth != nullptr; i++) {
                kth = kth->next;
            }
            if (kth == nullptr) {
                break; // Fewer than k nodes left; leave them untouched
            }

            // 2. 📍 Identify boundaries
            ListNode* groupHead = prevGroupTail->next;
            ListNode* nextGroupHead = kth->next;

            // 3. 🔄 In-place reversal of the k nodes
            ListNode* curr = groupHead;
            ListNode* prev = nextGroupHead; // Directly links new tail to next group
            for (int i = 0; i < k; i++) {
                ListNode* nextNode = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextNode;
            }

            // 4. 🔗 Connect the previous segment to the new group head
            prevGroupTail->next = kth;

            // 5. ⏭️ Move prevGroupTail forward for the next batch
            prevGroupTail = groupHead;
        }

        return dummy.next;
    }
};