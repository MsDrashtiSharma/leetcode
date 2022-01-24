/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
        private:unordered_map<Node*,Node*>m;
public:
    Node* cloneGraph(Node* node) {
            //bfs
        if(node==NULL)
                return NULL;
          /*  unordered_map<Node*,Node*>m;
         queue<Node*>q;
            q.push(node);
            m[node]=new Node(node->val);
            while(!q.empty())
            {
                    Node*curr=q.front();
                    q.pop();
                    for(auto ng:curr->neighbors)
                    {     //means if not find in map
                            if(!m.count(ng))
                            {
                             m[ng]=new Node(ng->val);
                                    q.push(ng);
                            }
                            m[curr]->neighbors.push_back(m[ng]);
                    }
            }
            return m[node];
            */
            
            if(m.find(node)==m.end())
            {
               m[node]=new Node(node->val);
                 for(auto ng:node->neighbors){
                         m[node]->neighbors.push_back(cloneGraph(ng));
                 }                       
            }
            return m[node];
            
    }
};