#include <stdio.h> 
#include <stdlib.h> 
  
/* A binary tree node has data, pointer to left child 
   and a pointer to right child */
struct node 
{ 
    int data; 
    struct node* left, *right; 
}; 
  
/* Function protoypes */
void printGivenLevel(struct node* root, int level); 
int height(struct node* node); 
struct node* newNode(int data); 
  
/* Function to print level order traversal a tree*/
void printLevelOrder(struct node* root) 
{ 
    int h = height(root); 
    int i; 
    for (i=1; i<=h; i++) 
        printGivenLevel(root, i); 
} 

//linkedlist for binary tree
void LinkedList(struct node* root , int k)
{
	if(root==NULL)
	{
		return;
	}
	struct node *temp= newNode(root->data);
	struct node *head , *last;
	if(k==1)
	{
		head->left=NULL;
		head->right=temp;
		temp->left=head;
		last=temp;
    }
    else
    {
     	last->right=temp;
     	temp->left=last;
	}
	printf("Level Order traversal of binary tree using Doubly linked list is \n");
	while(head!=NULL)
	{
	   printf("%d ", head->data);
	   head=head->right;
    }
  }  
  
/* Print nodes at a given level */
void printGivenLevel(struct node* root, int level) 
{ 
    int l=0;
    if (root == NULL) 
        return; 
    if (level == 1) 
    {
        l++;
        LinkedList(root,l); 
    }
    else if (level > 1) 
    { 
        printGivenLevel(root->left, level-1); 
        printGivenLevel(root->right, level-1); 
    } 
} 
  
/* Compute the "height" of a tree -- the number of 
    nodes along the longest path from the root node 
    down to the farthest leaf node.*/
int height(struct node* node) 
{ 
    if (node==NULL) 
        return 0; 
    else
    { 
        /* compute the height of each subtree */
        int lheight = height(node->left); 
        int rheight = height(node->right); 
  
        /* use the larger one */
        if (lheight > rheight) 
            return(lheight+1); 
        else return(rheight+1); 
    } 
} 
  
/* Helper function that allocates a new node with the 
   given data and NULL left and right pointers. */
struct node* newNode(int data) 
{ 
    struct node* node = (struct node*) 
                        malloc(sizeof(struct node)); 
    node->data = data; 
    node->left = NULL; 
    node->right = NULL; 
  
    return(node); 
} 
  
/* Driver program to test above functions*/
int main() 
{ 
    struct node *root = newNode(1); 
    root->left        = newNode(2); 
    root->right       = newNode(3); 
    root->left->left  = newNode(4); 
    root->left->right = newNode(5); 
  
    printf("Level Order traversal of binary tree is \n"); 
    printLevelOrder(root); 
    return 0; 
} 


