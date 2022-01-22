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
          bool helper(TreeNode* root, long left_bound, long right_bound)
    {
        if(root == NULL) return true; // an empty BST is technically valid
        
        if(root->val >= right_bound || root->val <= left_bound) // Point 1.
        {
            return false;
        }
        
        return
            helper(root->left, left_bound, root->val) // Point 2.
            &&
            helper(root->right, root->val, right_bound) // Point 3.
			;
    }
    
    bool isValidBST(TreeNode* root) {
        return helper(root, LONG_MIN, LONG_MAX);
    }

        
};