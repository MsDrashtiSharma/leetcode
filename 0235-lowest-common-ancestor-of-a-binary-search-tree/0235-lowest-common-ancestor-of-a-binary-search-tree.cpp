/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL)return NULL;
       // if((p->val<root->val&&q->val>root->val)||(p->val>root->val&&q->val>root->val))
       //   return root;
        if(p->val<root->val&&q->val<root->val)
        {
          //  if(root->left!=NULL)
            
            
                return lowestCommonAncestor(root->left,p,q);
        }
           
         if(p->val>root->val&&q->val>root->val)
        {
          //  if(root->right!=NULL)
           // {
                 return lowestCommonAncestor(root->right,p,q);
           // }
        }
          
            return root;
            
        
        
    }
};
// if(root==NULL)
//                 return NULL;
//             int cur=root->val;
//             if(cur<p->val&&cur<q->val)
//                   return lowestCommonAncestor(root->right,p,q)  ;
//             if(cur>p->val&&cur>q->val)
//                  return  lowestCommonAncestor(root->left,p,q)  ;
//            return root; 