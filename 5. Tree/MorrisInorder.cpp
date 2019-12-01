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
//Morris Inorder traversal of a binary tree*/
 void MorrisInorder(struct Node* root) 
{ 
    struct Node *current, *pre; 
  
    if (root == NULL) 
        return; 
  
    current = root; 
    while (current != NULL) { 
  
        if (current->left == NULL) 
		{ 
            cout<<current->key<<" " ;
            current = current->right; 
        } 
        else 
		{ 
  
            /* Find the inorder predecessor of current */
            pre = current->left; 
            while (pre->right != NULL && pre->right != current) 
                pre = pre->right; 
  
            /* Make current as the right child of its inorder  
               predecessor */
            if (pre->right == NULL) 
			{ 
                pre->right = current; 
                current = current->left; 
            } 
  
            /* Revert the changes made in the 'if' part to restore  
               the original tree i.e., fix the right child 
               of predecessor */
            else 
			{ 
                pre->right = NULL; 
                cout<<current->key<<" " ;
                current = current->right; 
            } /* End of if condition pre->right == NULL */
        } /* End of if condition current->left == NULL*/
    } /* End of while */
} 
  
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
	cout<<"normal inordr: ";
   inorder(root);
   cout<<"\nMorris inordr: ";
   MorrisInorder(root);
    return 0; 
} 



