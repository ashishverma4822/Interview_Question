class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* fast=head;
        ListNode* slow=head;
        if(head==NULL || head->next==NULL){
            return head;
        }else{
            while(fast!=NULL && fast->next!=NULL){
                slow=slow->next;
                fast=fast->next->next;
            
            }
        }
        return slow;
    }
};
