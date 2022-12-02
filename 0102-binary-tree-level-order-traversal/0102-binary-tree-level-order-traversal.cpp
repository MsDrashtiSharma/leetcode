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
    vector<vector<int>> levelOrder(TreeNode* root) {
       vector<vector<int>>v;
        queue<TreeNode*>q;
        if(root==NULL)
            return v;
        q.push(root);
        while(!q.empty())
        {
            int l=q.size();
            vector<int>p;
            for(int i=1;i<=l;i++)
            {    
                TreeNode*lp=q.front();
                q.pop();
                if(lp->left!=NULL)
                {
                    q.push(lp->left);
                    
                }
                if(lp->right!=NULL)
                {
                    q.push(lp->right);
                }
               p.push_back(lp->val);
                
                
            }
            v.push_back(p);
        }
        return v;
    }
};