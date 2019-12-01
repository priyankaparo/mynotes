#include <iostream> 
#include <queue>
#include <bits/stdc++.h>  
using namespace std; 
  
/* A binary tree node has key, pointer to left child 
and a pointer to right child */
struct Node { 
    int key; 
    struct Node* left, *right; 
}; 
  
/* function to create a new node of tree and r 
   eturns pointer */
struct Node* newNode(int key) 
{ 
    struct Node* temp = new Node; 
    temp->key = key; 
    temp->left = temp->right = NULL; 
    return temp; 
}; 
  
/* Inorder traversal of a binary tree*/
void inorder(struct Node* temp) 
{ 
    if (!temp) 
        return; 
  
    inorder(temp->left); 
    cout << temp->key << " "; 
    inorder(temp->right); 
} 
  
/*function to insert element in binary tree */
struct Node* insert(struct Node* root, int key) 
{ 
    struct Node* temp=root;
    if(root==NULL)
    {
    	root=newNode(key);
    	return root;
	}
    queue<struct Node*> q; 
    q.push(temp); 
     
    // Do level order traversal until we find 
    // an empty place.  
    while (!q.empty()) { 
        struct Node* temp = q.front(); 
        q.pop(); 
  
        if (!temp->left) { 
            temp->left = newNode(key); 
            break; 
        } else
            q.push(temp->left); 
  
        if (!temp->right) { 
            temp->right = newNode(key); 
            break; 
        } else
            q.push(temp->right); 
    } 
    return root;
} 
  
void ZIGZAG(struct Node * root) 
{ 
int flag=0;
    // Base case 
    if (root == NULL) 
        return; 
  
 
    stack<Node*> q;
	 Node *temp1=NULL;
    stack<Node*> p;
    p.push(root); 
    while (!p.empty()) 
    { 
        // Get the size of queue when the level order 
        // traversal for one level finishes 
        int count = p.size() ; 
        
        // Iterate for all the nodes in the queue currently 
        
        while (count--) 
        { 
            // Dequeue an node from queue 
            Node *temp = p.top(); 
            p.pop(); 
            // Add this node's value to current sum. 
		    if(flag==0)
		    {
		   // push right and left children of 
	            // dequeued nodde for zizzag
	            cout<<temp->key<<" ";
	            if (temp->right != NULL) 
	                q.push(temp->right); 
	            if (temp->left != NULL) 
	                q.push(temp->left); 
			}
            else
            {
            	cout<<temp->key<<" ";
            	if (temp->left != NULL) 
	                q.push(temp->left);
	            if (temp->right != NULL) 
	                q.push(temp->right); 
             	
			}
			
			if (p.empty()) 
			{ 
	            flag = !flag; 
	            swap(p, q);
            } 
  
    }
    cout<<"\n";
}  }
    
// Driver code 
int main() 
{ 
int i,n,key,givenlevel;
    struct Node* root = new Node();
    root=NULL;
    cout<<"enter no of: ";
    cin>>n;
    cout<<"enetr elements: ";
    for(i=0;i<n;i++)
    {
	    cin>>key; 
	    root=insert(root, key); 
	}
    ZIGZAG(root);
    return 0; 
} 



