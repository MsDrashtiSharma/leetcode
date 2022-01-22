/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        //vector<vector<int>>v;
            queue<Node*>q;
            if(root==NULL)
                    return root;
            q.push(root);
            while(!q.empty())
            {
                    int size=q.size();
                  //  vector<int>l;
                    Node*temp;
                    for(int i=1;i<=size;i++)
                    {
                            if(i<size)
                            {
                                    temp=q.front();
                                    q.pop();
                                    Node*nex=q.front();
                                    temp->next=nex;
                            }
                            else
                            {
                                    temp=q.front();
                                    q.pop();
                            }
                            if(temp->left!=NULL)
                                    q.push(temp->left);
                            if(temp->right!=NULL)
                                    q.push(temp->right);
                            
                        
                    }
                    
            }
            return root;
    }
};