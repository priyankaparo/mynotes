#include<iostream>
using namespace std;

struct node
{
	int data;
	node *left,*right;
};

struct node* newNode(int val)
{
	node *temp =new node();
	temp->data=val;
	temp->left=temp->right=NULL;
	return temp;
}

//recursive approach

struct node* insert_recursive(struct node *root , int num)
{
	struct node *temp= newNode(num);
	//if there is no elemnt in tree then return that node
	if(root==NULL)
	{
		return temp;
	}
	//if value is less then root data then insert into left tree
	else if(num<(root->data))
	{
		root->left=insert_recursive(root->left , num);
	}
	//if value is greater then root data then insert into right tree
	else if(num>(root->data))
	{
		root->right=insert_recursive(root->right, num);
	}
	return root;
}

//iterative approach

struct node* insert_iterative(struct node *root , int num)
{
	struct node *temp= newNode(num);
	struct node *curr=root;
	struct node *prev=NULL;
	if(root==NULL)
	{
		root=temp;
	}
	//find the node where we want to insert data
	while(curr!=NULL)
	{
		prev=curr;
		if(num<curr->data)
		{
			curr=curr->left;
		}
		else
		{
			curr=curr->right;
		}
	}
	//if there is no elemnt in tree then return that node
	if(prev==NULL)
	{
		prev=temp;
	}
	//if value is less then root data then insert into left tree
	else if(num<prev->data)
	{
		prev->left=temp;
	}
	//if value is greater then root data then insert into right tree
	else
	{
		prev->right=temp;
	}
	
	return root;
}

void inorder(struct node *root) 
{ 
    if (root != NULL) 
    { 
        inorder(root->left); 
        cout<<root->data<<endl;
        inorder(root->right); 
    } 
} 
//recursive searching
int search_recursive(node *root , int k)
{
	int flag=0;
	if(k==root->data)
	{
		flag=1;
		cout<<"\nelement found";
		return flag;
	}
	//if value is less then root data then insert into left tree
	else if(k<(root->data))
	{
		search_recursive(root->left , k);
	}
	//if value is greater then root data then insert into right tree
	else if(k>(root->data))
	{
		search_recursive(root->right, k);
	}
	return flag;
}
//iterative searching 
int search_iterative(node *root , int k)
{
	struct node *curr=root;
	if(root==NULL)
	{
	  return 0;	
	}
	//find the node where we want to insert data
	while(curr!=NULL)
	{
		if(k==curr->data)
		{
			cout<<"element found";
			return 1;
		}
		else if(k<curr->data)
		{
			curr=curr->left;
		}
		else
		{
			curr=curr->right;
		}
	}
	return 0;
}

struct node * minValueNode(struct node* node) 
{ 
    struct node* current = node; 
  
    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL) 
        current = current->left; 
  
    return current; 
} 
  
/* Given a binary search tree and a key, this function deletes the key 
   and returns the new root */
struct node* deleteNode(struct node* root, int key) 
{ 
    // base case 
    if (root == NULL) return root; 
  
    // If the key to be deleted is smaller than the root's key, 
    // then it lies in left subtree 
    if (key < root->data) 
        root->left = deleteNode(root->left, key); 
  
    // If the key to be deleted is greater than the root's key, 
    // then it lies in right subtree 
    else if (key > root->data) 
        root->right = deleteNode(root->right, key); 
  
    // if key is same as root's key, then This is the node 
    // to be deleted 
    else
    { 
        // node with only one child or no child 
        if (root->left == NULL) 
        { 
            struct node *temp = root->right; 
            delete(root); 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
            struct node *temp = root->left; 
            delete(root); 
            return temp; 
        } 
  
        // node with two children: Get the inorder successor (smallest 
        // in the right subtree) 
        struct node* temp = minValueNode(root->right); 
  
        // Copy the inorder successor's content to this node 
        root->data = temp->data; 
  
        // Delete the inorder successor 
        root->right = deleteNode(root->right, temp->data); 
    } 
    return root; 
} 

int main()
{
	int n,val,i,element;
	struct node *root = NULL;
	cout<<"enter no of the elements of tree: ";
	cin>>n;
	cout<<"\nenter the elements of tree: ";
	for(i=0;i<n;i++)
	{
		cin>>val;
		root=insert_iterative(root , val);
	}
	inorder(root);
/*	cout<<"enter searchingelemnet: ";
	cin>>element;
	int flag=search_recursive(root,element); // or can use iterative approach also 
	if(flag==0)
	{
		cout<<"\nelement not found:";
	}*/
	int key;
	cout<<"deleted item: ";
	cin>>key;
	 root= deleteNode(root, key) ;
	 inorder(root);
	return 0;
}


