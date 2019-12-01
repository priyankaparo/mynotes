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

void inorder(struct node *root) 
{ 
    if (root != NULL) 
    { 
        inorder(root->left); 
        cout<<root->data<<endl;
        inorder(root->right); 
    } 
} 
int Size(node* root)  
{  
    if (root == NULL)  
        return 0;  
    else
    {  
        /* compute the height of each subtree right and left*/
        int lheight = Size(root->left);  
        int rheight = Size(root->right);  
      
        /* use themaximum  one height of right or left*/
        return (lheight+rheight+1);  
    }  
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
		root=insert_recursive(root , val);
	}
	inorder(root);
    int p=Size(root);
    cout<<"size of tree: "<<p;
	return 0;
}


