class Solution {
public:
    ListNode* swapPairs(ListNode* head) {

        if(head == NULL || head->next == NULL)
            return head;//if head-> next==null means there is only one node no second node to swap so return head

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* point = dummy;

        while(point->next != NULL && point->next->next != NULL) {

            ListNode* swap1 = point->next;
            ListNode* swap2 = point->next->next;

            swap1->next = swap2->next;
            swap2->next = swap1;

            point->next = swap2;
            point = swap1;
        }

        return dummy->next;
    }
};
