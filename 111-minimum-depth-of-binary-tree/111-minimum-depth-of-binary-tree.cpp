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
    int minDepth(TreeNode* root) {
  /* // special case : empty tree
        if (root == nullptr) return 0;
        // DFS
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        // TWO CASE:
        //  1) left/right tree has/both empty, empty one will return 0, "left + right + 1"
        //  2) left/right tree both not empty, both return positive depth, "std::min() + 1" 
        return (left == 0 || right == 0) ? left + right + 1 : min(left, right)+1;
        */
        
        if(!root) return 0;
        queue<TreeNode*>q;
        q.push(root);
        int level=0;
            while(!q.empty())
            
            {
                int s=q.size();
                level++;
               for(int i=0;i<s;i++)
                {
                    TreeNode *parent=q.front();
                    q.pop();
                    if(parent->left)
                        q.push(parent->left);
                    if(parent->right)
                        q.push(parent->right);
                    if(!parent->left&&!parent->right)
                    
                        return level;
                    
                }
            }
        return -1;
        
        
    }
};