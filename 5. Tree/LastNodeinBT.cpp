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

int maxDepth(Node* node)  
{  
    if (node == NULL)  
        return 0;  
    else
    {  
        /* compute the depth of each subtree */
        int lDepth = maxDepth(node->left);  
        int rDepth = maxDepth(node->right);  
      
        /* use the larger one */
        if (lDepth > rDepth)  
            return(lDepth + 1);  
        else return(rDepth + 1);  
    }  
}  

void LastNode(struct Node * root) 
{ 
	int i=0,k=0,level=1,height;
	int a[100];
    height=maxDepth(root);
    cout<<"height: "<<height<<endl;
    // Base case 
    if (root == NULL) 
        return; 
  
    // Do Level order traversal keeping track of number 
    // of nodes at every level. 
    queue<Node*> q; 
    q.push(root); 
    while (!q.empty()) 
    { 
        // Get the size of queue when the level order 
        // traversal for one level finishes 
        int count = q.size() ; 
        while (count--) 
        { 
            // Dequeue an node from queue 
            Node *temp = q.front(); 
            q.pop(); 
             cout<<temp->key<<" ";
             if(level==height)
            {
              k++;
        	  a[i]=temp->key;
        	  i++;
		    }
		    
            // Enqueue left and right children of 
            // dequeued node 
            if (temp->left != NULL) 
                q.push(temp->left); 
            if (temp->right != NULL) 
                q.push(temp->right); 
                
        } 
        cout<<"\n";
        level++;
    }  
    cout<<"last node value: "<<a[k-1];
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
    LastNode(root);
    cout << endl; 
    
    return 0; 
} 



