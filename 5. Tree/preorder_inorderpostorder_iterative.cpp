#include<iostream>
#include<stack>
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
void inorder_iterative(struct node*root)
{
	stack<struct node*> st;
	struct node*curr=root;
	while(curr!=NULL || !st.empty())
	{
		
		while(curr!=NULL)
		{
			st.push(curr);
			curr=curr->left;
		}
		curr = st.top(); 
        st.pop();
        cout<<curr->data<<" ";
        curr=curr->right;
        
	}
}
void preorder_iterative(struct node*root)
{
	stack<struct node*> st;
	struct node*curr=root;
	st.push(curr);
	while(!st.empty())
	{
		curr=st.top();
		st.pop();
		cout<<curr->data<<" ";
		if(curr->right)
		{
			st.push(curr->right);
		}
		if(curr->left)
		{
			st.push(curr->left);
		}
		
		
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
		root=insert_iterative(root , val);
	}
	preorder_iterative(root);
	return 0;
}


