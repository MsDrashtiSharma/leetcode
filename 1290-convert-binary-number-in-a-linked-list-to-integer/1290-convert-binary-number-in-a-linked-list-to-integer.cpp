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
    int getDecimalValue(ListNode* head) {
           /* int sum=0;
            ListNode *p;
      for(p=head;p!=NULL;p=p->next)
      {     if(p->val==0)
              sum=sum+p->val;
              else
              sum=sum+pow(2,p->val);
      }
            return sum;*/
            int res=0;
        while(head!=NULL){
            res=res*2+head->val;
            head=head->next;
        }
        return res;
    }
};