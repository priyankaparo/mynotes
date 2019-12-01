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
  
void Delete(struct Node*root)
{
	
	if(root==NULL)
	{
		return;
	}
	
	Delete(root->left);
	Delete(root->right);
	
	cout<<"\n deleted elemnts of tree: "<<root->key;
	delete(root);
	
}
// Driver code 
int main() 
{ 
int i,n,key;
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
    Delete(root);
    root=NULL;
    return 0; 
} 



