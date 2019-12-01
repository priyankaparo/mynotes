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
	    return head;}}

//deletion of a node
void Deletenode(node* head,int n)
{
	int choice,key;
	node* temp1,*temp2,*head1=head;
	cout<<"\nEnter your choice to delete (by number,enter-->0 and if by index,enter-->1: ";
	cin>>choice;
	
	///deletion of a node by a number so at first we will search that number
	if(choice==0)
	{
		cout<<"\nenter elemnt fro deletion: ";
		cin>>key;
		if(head1->next==NULL)
		{
			//searching of number and deketion of node
			if(head1->data==key)
			{
				cout<<"\nelement deleted";
				delete head;
				return;
			}
		}
		else
		{
			while(head1!=NULL)
			{
				if(head1->next->data==key)
				{
				  temp1=head1->next;
				  temp2=head1->next->next;
				  head1->next=temp2;
				  delete temp1;
				  cout<<"\nelemnt deleted";
				  return;
			    }
			    head1=head1->next;
			}
		}
		cout<<"\nElement doesnt exist in Linked list";
	}
	
	






//deletion by index number
	else if(choice==1)
	{
		int pos;
		cout<<"\nenter position for deltion: ";
		cin>>pos;
		//if at first position then delete the head node
		if(pos==1)
		{
			temp1=head;
			head=head->next;
			delete temp1;
			 cout<<"\nelemnt deleted";
			 return;
		}
		//otherwise go till that (pos-1)index
		else
		{
			for(i=1;i<pos;i++)
			{
				temp1=head1->next;
			    head1=head1->next;
			}
			temp2=head1->next->next;
			head1->next=temp2;
			delete temp1;
			 cout<<"\nelemnt deleted";
			return;
		}
		cout<<"\nElement doesnt exist in Linked list";
	}
}

//seasrching of elemnt which exist in linked list or not
void Searching_num(node* head)
{
	int searching_num;
	node* head1=head;
	cout<<"\nEnter searching elemnt: " ;
	cin>>searching_num;
	while(head1!=NULL)
	{
		if(head1->data==searching_num)
		{
		  cout<<"\nelemnt found";
		  return;
	    }
	    head1=head1->next;
	}
	cout<<"\nelemnt not found";
}

//printing of linked list
void printList(node* head,int n)
{
	node* head1;
	head1=head;
	while(head1!=NULL)
	{
		cout<<head1->data<<" ";
		head1=head1->next;
	}
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
	printList(head,n);
	//searching in linked list
	Searching_num(head);
	//deletion function in linked list
	Deletenode(head,n);
	return 0;
}



