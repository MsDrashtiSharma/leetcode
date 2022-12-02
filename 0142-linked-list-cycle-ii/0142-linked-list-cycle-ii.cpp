/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow=head;
        ListNode *fast=head;
        if(head==NULL||head->next==NULL)
            return NULL;
        while(fast!=NULL&&fast->next!=NULL)
        {  
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            break;
        }
        if(fast==NULL||fast->next==NULL)
            return NULL;
        ListNode *ptr=slow;
        ListNode *ptr1=head;
        while(ptr!=ptr1)
        {
           ptr=ptr->next;
            ptr1=ptr1->next;
        }
        return ptr;
        
    }
};