#include<iostream>
using namespace std;

//creation of a node
struct node
{
	int data;
	node *next;
};

//creation of a new node with data value
node* Createnode(int num)
{
	node* temp =new node(); ;
	temp->data=num;
	temp->next= NULL;
	return temp;
}

//insertion of a node
node* Insertnode(node* head,int k)
{
	int pos;
	cout<<"enter the position where u want to add node(enter 0-->begin or 1-->end) : ";
	cin>>pos;
	
	//insertion at beginning
	if(pos==0)
	{
		node*temp=Createnode(k);
		temp->next=head;
		head=temp;
		return head;
	}
	
	//insertion at last
	else if(pos==1)
	{
	    node* head1=head;
		
		node* temp=Createnode(k);
		if(head==NULL)
		{
			head=temp;
		}
		





else
		{
			while(head1->next!=NULL)
			{
				head1=head1->next;
			}
			head1->next=temp;
	    }
	    return head;
	}
	
}

//printing of linked list
void printList(node* head)
{
	node* head1;
	head1=head;
	while(head1!=NULL)
	{
		cout<<head1->data<<" ";
		head1=head1->next;
	}
}

//reversing the linked list using recursive method
node* printList_Recursive(node* head)
{
	node* curr=head;
    if(head == NULL) 
    {
    	return NULL; // linked list does not exist.
	}

    if(head->next == NULL) 
	{
	      return head; //linked list with only one node.
	}

   curr = printList_Recursive(head->next); // recursive call on curr.

   head->next->next = head; // linked link to the last node in the reversed curr.

   head->next = NULL; // since head is the new last, make its link NULL.

   return curr; 
}




//main program
int main()
{
	int i,num,n,searching_num;
	node* head=new node();
	head=NULL;
	cout<<"enter the number of elemnts for linked list: ";
	cin>>n;
	//insertion at linked list
	for(i=1;i<=n;i++)
	{
		cout<<"\nenter the element for linked list: ";
		cin>>num;
		head=Insertnode(head,num);
	 }
	
	//printing of linked list
	printList(head);
	
	cout<<"\nReverse of linked list: ";
	//reversing the linked list using iterative method
	head=printList_Recursive(head);
	printList(head);
	return 0;
}


