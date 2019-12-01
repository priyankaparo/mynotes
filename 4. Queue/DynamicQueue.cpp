#include<iostream>
#include<conio.h>

using namespace std;

struct node
{
      int data;
      node *next;
};

node *rear,*front;

void enqueue()
{
      node *temp;
      temp=new node;
      cout<<"Data :";
      cin>>temp->data;
      temp->next=NULL;
      if(rear==NULL)
      {
            rear=temp;
            front=temp;
      }
      else
      {
            rear->next=temp;
            rear=temp;
      }
}

void dequeue()
{
      if(front!=NULL)
      {
            node *temp=front;
            cout<<front->data<<"deleted \n";
            front=front->next;
            delete temp;
            if(front==NULL)
                  rear=NULL;
      }
      else
            cout<<"Queue Empty..";
}

void display()
{
      node *temp=front;
      while(temp!=NULL)
      {
            cout<<temp->data<<endl;
            temp=temp->next;
      }
}

int main()
{
      int i;

      do
      {
      	cout<< "1. insert\n 2. Delete\n 3. Display\n 4. exit";
        cin>>i;
	  
            switch(i)
            {
                  case 1 : enqueue();break;
                  case 2 : dequeue();break;
                  case 3 : display();
            }
      
  }while (i!=4);
      return 0;
}



