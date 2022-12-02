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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
       
       
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
         ListNode* list1=NULL;
        if(l1->val < l2->val)       
        { list1 = l1; 
         l1 = l1->next;
        }
        else                        
        { 
            list1 = l2; 
            l2 = l2->next; 
        }
        
        
        ListNode *list=list1;
        while(l1&&l2)
        {
            if(l1->val>l2->val)
            {
                list->next=l2;
                l2=l2->next;
            }
                
            else 
            {
               list->next=l1;
                l1=l1->next;
               
            }
                 list=list->next;
        }
//         while(l1)
//         {
//             list->next=l1;
//              l1=l1->next;
//              list=list->next;
//         }
//         while(l2)
//         {
            
//              list->next=l2;
//             l2=l2->next;
//              list=list->next;
      //  }
        if(l1) 
        list->next=l1;
    else   
        list->next=l2;
        
        return list1;
        
        
    }
};