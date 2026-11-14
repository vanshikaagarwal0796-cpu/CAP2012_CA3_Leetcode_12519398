class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* temp = head;
        int count = 0;

        // Check whether k nodes are available
        while(temp != NULL && count < k) {
            temp = temp->next;
            count++;
        }

        // If less than k nodes are present
        if(count < k)
            return head;

        // Reverse k nodes
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;

        for(int i = 0; i < k; i++) {

            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // Connect remaining list
        head->next = reverseKGroup(curr, k);

        return prev;
    }
};
