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
    ListNode* deleteDuplicates(ListNode* head) {
      ListNode* dummy=new ListNode(0);
       if(head==NULL||head->next==NULL)
               return head;
            dummy->next=head;
            ListNode*prev=dummy;
            ListNode*it=head;
            
            while(it!=NULL&&it->next!=NULL)
            {bool findduplicate=false;
             while(it!=NULL&&it->next!=NULL&&it->val==it->next->val)
             {
                     findduplicate=true;
                     it=it->next;
             }       
                    
             if(findduplicate)
             {
                     prev->next=it->next;
             }
             else
             {
                     prev=prev->next;
             }
             it=it->next;
            }
            return dummy->next;
    }
};