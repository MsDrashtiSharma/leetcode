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
    ListNode* partition(ListNode* head, int x) {
        ListNode* small=new ListNode(0);
        ListNode* high=new ListNode(0);
            ListNode* highnode=high;ListNode*smallnode=small;
            while(head!=NULL)
            { if(head->val<x)
            {
                    smallnode->next=head;
                    smallnode=smallnode->next;
            }
            else
            {
                     highnode->next=head;
                    highnode=highnode->next;
            }
             head=head->next;
            }
            smallnode->next=high->next;
            highnode->next=NULL;
            
return small->next;
    }
};