
#include<iostream>
using namespace std;


#define MAXSTACK 100        // for max size of stack 
#define POSTFIXSIZE 100     //define max number of charcters in postfix expression 

 int stack[MAXSTACK];
 int top = -1 ;             
 //push operation of stack
 void push(int item)
 {

	 if(top >= MAXSTACK -1)
	 {
		 cout<<"stack over flow ";
		 return;
	 }
	 else
	 {
		 top = top + 1 ;
		 stack[top]= item;
	 }
 }

 //pop operation od stack
 int pop()
 {
	 int item;
	 if(top <0)
	 {
	  cout<<"stack under flow";
	 }
	 else
	 {
		 item = stack[top];
		 top = top - 1;
		 return item;
	 }
 }

//postfix evaluation fnxn
 void SolPostfix(char postfix[])
 {

	int i ;
	char ch;
	int val;
	int A, B ;

	for (i = 0 ; postfix[i] != ')'; i++)
	{
		ch = postfix[i];
		// if there is an operand,push the digit onto stack
		if (isdigit(ch))
		{
			
			//ch - '0' is used for getting digit rather than ASCII code of digit
			push(ch - '0');
		}
		//if there is an operator pop top elelmnt A and next-to-top elemnet B from stack and compute B operator A
		else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
		{
			 
			A = pop();
			B = pop();

			switch (ch) 
			{
				case '*':
				val = B * A;
				break;

				case '/':
				val = B / A;
				break;

				case '+':
				val = B + A;
				break;

				case '-':
				val = B - A;
				break;
			}

		// push the value obtained above onto the stack
			push(val);
		}
	}
	cout<<" Postfix Evalution Result is :";
	cout<<pop();
 }

 int main()
 {

	int i ;

	//declare character array to store postfix expression
	char postfix[POSTFIXSIZE];
	
    cout<<"enter valid postfix expression : ";
	for (i = 0 ; i < POSTFIXSIZE ; i++)
	{
		cin>>postfix[i];
		
		if ( postfix[i] == ')' )
		{ 
		   break;
		 }
	}


	SolPostfix(postfix);
	
	return 0;
 }



