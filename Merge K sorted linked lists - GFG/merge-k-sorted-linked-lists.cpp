//{ Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}

// } Driver Code Ends
/*Linked list Node structure

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/ 

class Solution{
  public:
    //Function to merge K sorted linked list.
    Node* merge(Node*l1,Node* l2)
     {
       

        Node *h = new Node(0);
    Node *ans=h;
    while (l1 != NULL && l2 != NULL) {
        if (l1->data < l2->data) {
            h->next = l1;
            h = h->next;
            l1 = l1->next;
        } else {
            h->next = l2;
            h = h->next;
            l2 = l2->next;
        }
    }
    if(l1==NULL){
        h->next=l2;
    }
    if(l2==NULL){
        h->next=l1;
    } 
    return ans->next;
     }
    Node * mergeKLists(Node *lists[], int k)
    {
            if(k==1){
        return lists[0];
    }
    if(k==0){
        return NULL;
    }
        //int k=lists.size();
    Node*t1=lists[0];
     for(int i=1;i<k;i++)   
     {  Node*t2=lists[i];
         t1=merge(t1,t2);
     }
     return t1;
           
    }
};



//{ Driver Code Starts.
// Driver program to test above functions
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
	   int N;
	   cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
   		}
   		Solution obj;
   		Node *res = obj.mergeKLists(arr,N);
		printList(res);

   }

	return 0;
}

// } Driver Code Ends