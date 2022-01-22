/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& p) {
        int i=0;
       // vector<int>v;
        return bst(i,p,INT_MAX);    
    }
        TreeNode*bst(int &i,vector<int>& p,int bound)
        {
                if(i==p.size()||p[i]>bound)
                        return NULL;
                TreeNode *root=new TreeNode(p[i]);
                i++;
                root->left=bst(i,p,root->val);
                root->right=bst(i,p,bound);
                return root;
                
        }
};