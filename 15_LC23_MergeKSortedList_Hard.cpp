class Solution {
public:

    // Function to merge two sorted lists
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode* dummy = new ListNode(0);
ListNode* temp = dummy;

        while(list1 != NULL && list2 != NULL) {

            if(list1->val <= list2->val) {
                temp->next = list1;
                list1 = list1->next;
            }
            else {
                temp->next = list2;
                list2 = list2->next;
            }

            temp = temp->next;
        }

        if(list1 != NULL)
            temp->next = list1;
        else
            temp->next = list2;

        return dummy->next;
    }

    // Merge k sorted lists
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        ListNode* ans = NULL;

        for(int i = 0; i < lists.size(); i++) {
            ans = mergeTwoLists(ans, lists[i]);
        }

        return ans;
    }
};
