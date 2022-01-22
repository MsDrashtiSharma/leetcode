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
          bool valid(TreeNode* root, long minval, long maxval)
    {
        if(root == NULL) return true; // an empty BST is technically valid
        
        if(root->val >= maxval || root->val <= minval) // Point 1.
        {
            return false;
        }
        
        return
            valid(root->left, minval, root->val) // Point 2.
            &&
            valid(root->right, root->val, maxval) // Point 3.
			;
    }
    
    bool isValidBST(TreeNode* root) {
        return valid(root, LONG_MIN, LONG_MAX);
    }

        
};