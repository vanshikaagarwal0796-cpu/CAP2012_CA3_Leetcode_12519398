class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode*curr=head,*prev=NULL,*temp;
        while(curr!=NULL){
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        head=prev;
        return head;
    }
};
