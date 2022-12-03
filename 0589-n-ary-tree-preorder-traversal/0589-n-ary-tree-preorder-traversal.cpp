/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
     void func(Node* root,vector<int> &ans){
        ans.push_back(root->val);
        for(int i=0;i<root->children.size();i++)
        {
            func(root->children[i],ans);
        }
       
    }

    vector<int> preorder(Node* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        func(root,ans);
        return ans;
    }
};
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
       // vector<int>v;
       //  queue<Node*>q;
       //  if(root==NULL)
       //      return v;
       //  q.push(root);
       //  while(!q.empty())
       //  {//int size=q.size();
       //   //vector<int>l;
       //   //for(int i=0;i<size;i++)
       //   //{
       //       Node *node=q.front();
       //       q.pop();
       //       while(node->children)
       //           q.push(node->children);
       //       // if(node->right!=NULL)
       //       //     q.push(node->right);
       //       v.push_back(node->val);
       //   }
       //     // v.push_back(l);
       // // }
       //  return v;  
//     }
// };