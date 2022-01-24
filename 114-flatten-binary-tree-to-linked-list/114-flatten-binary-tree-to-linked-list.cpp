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
   /*     TreeNode * prev=NULL;
    void flatten(TreeNode* root) {
        tc o(n),sc o(n) recursive
            if(root==NULL)
                    return;
            flatten(root->right);
                    flatten(root->left);
    root->right=prev;
            root->left=NULL;
            prev=root;
            */
        
        void flatten(TreeNode* root)
        {
        stack<TreeNode*>s;
        s.push(root);
                TreeNode*curr;
                if(root==NULL)
                        return ;
                while(!s.empty())
                {         
                        curr=s.top();
                        s.pop();
                        if(curr->right)
                                s.push(curr->right);
                        if(curr->left)
                                s.push(curr->left);
                        if(!s.empty())
                        {
                                curr->right=s.top();
                        }
                        curr->left=NULL;
                        
                }
        }
        
    
};