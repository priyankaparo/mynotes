#include <iostream> 
#include <queue> 
using namespace std; 
  
/* A binary tree node has key, pointer to left child 
and a pointer to right child */
struct Node { 
    int key; 
    struct Node* left, *right, *nextRight; 
}; 
  
/* function to create a new node of tree and r 
   eturns pointer */
struct Node* newNode(int key) 
{ 
    struct Node* temp = new Node; 
    temp->key = key; 
    temp->left = temp->right =temp->nextRight= NULL; 
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
    while (!q.empty()) 
	{ 
        struct Node* temp = q.front(); 
        q.pop(); 
	
		        if (!temp->left)
				 { 
		            temp->left = newNode(key); 
		            break; 
		        } else
		            q.push(temp->left); 
		  
		        if (!temp->right) 
				{ 
		            temp->right = newNode(key); 
		            break; 
		        } 
				else
		            q.push(temp->right); 
	        
	        
    } 
    return root;
} 
void ConnectPeers(struct Node *root)
{
	queue<struct Node*> q; 
    q.push(root); 
  
    // null marker to represent end of current level 
    q.push(NULL);  
  
    // Do Level order of tree using NULL markers 
    while (!q.empty()) { 
       struct Node *p = q.front(); 
        q.pop(); 
        if (p != NULL) 
		{ 
  
            // next element in queue represents next  
            // node at current Level  
            p->nextRight = q.front(); 
  
            // push left and right children of current 
            // node 
            if (p->left) 
                q.push(p->left);  
            if (p->right) 
                q.push(p->right); 
        }  
         
        // if queue is not empty, push NULL to mark  
        // nodes at this level are visited 
        else if (!q.empty())  
            q.push(NULL);  
    } 
}
  
void maxLevelSum(struct Node * root) 
{ 
    // Base case 
    if (root == NULL) 
        return; 
  
    // Initialize result
	int level=0; 
    int result = root->key; 
  
    // Do Level order traversal keeping track of number 
    // of nodes at every level. 
    queue<Node*> q; 
    q.push(root); 
    while (!q.empty()) 
    { 
        // Get the size of queue when the level order 
        // traversal for one level finishes 
        int count = q.size() ; 
  
        // Iterate for all the nodes in the queue currently 
        int sum = 0; 
        while (count--) 
        { 
            // Dequeue an node from queue 
            Node *temp = q.front(); 
            q.pop(); 
  
            // Add this node's value to current sum. 
            sum = sum + temp->key; 
             cout<<temp->key<<" ";
            // Enqueue left and right children of 
            // dequeued node 
            if (temp->left != NULL) 
                q.push(temp->left); 
            if (temp->right != NULL) 
                q.push(temp->right); 
        } 
        cout<<"\n";
  
        // Update the maximum node count value 
        //result = max(sum, result);
        if(sum>result)
        {
        	result=sum;
        	level++;
		}
		 
    } 
  
    cout<<"max sum: "<<result<<"at level: "<<level; 
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
  
    cout << endl; 
    cout << "levelorder traversal after insertion:"; 
    maxLevelSum(root); 
    ConnectPeers(root);
  cout<<"\nnext to 2 is"<<(root->left->nextRight->key)<<endl;
    return 0; 
} 



