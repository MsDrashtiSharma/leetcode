/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
    if(head==NULL ||head->next==NULL)
            return head;
            ListNode *oddit=head;
            ListNode *evenit=head->next;
            ListNode *evenhead=evenit;
            while(oddit->next!=NULL&&evenit->next!=NULL)
            {
                    ListNode *oddnext=evenit->next;
                    oddit->next=oddnext;
                    oddit=oddit->next;
                    if(oddit!=NULL)
                    {
                            evenit->next=oddit->next;
                            evenit=evenit->next;
                    }
            }
            oddit->next=evenhead;
            return head;
    }
};