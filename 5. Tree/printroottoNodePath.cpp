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

int path[1000]; 

void printNodePath(Node* curr, int path[], int pathLen)  
{  
    if (curr == NULL)  
        return;  
      
    /* append this node to the path array */
    path[pathLen] = curr->key;  
    pathLen++;  
      
    /* it's a leaf, so print the path that led to here */
    if (curr->left == NULL && curr->right == NULL)  
    {  
	    int i;  
	    for (i = 0; i < pathLen; i++)  
	    {  
	        cout << path[i] << " ";  
	    }  
	    cout<<endl;
        //printArray(path, pathLen);  
    }  
    else
    {  
        /* otherwise try both subtrees */
        printNodePath(curr->left, path, pathLen);  
        printNodePath(curr->right, path, pathLen);  
    }  
}  
  
  

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
    printNodePath(root,path,0);
     
    
    return 0; 
} 



