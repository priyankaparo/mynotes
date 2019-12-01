#include<iostream>
#include<string.h>
using namespace std;

#define SIZE 100

char stack[SIZE];
int top = -1;

// push function for stack
void push(char item)
{
	if(top >= SIZE-1)
	{
		cout<<"Stack Overflow.";
	}
	else
	{
		stack[++top] = item;
	}
}

//pop function for stack
char pop()
{
	char element ;

	if(top <0)
	{
		cout<<"stack under flow: invalid infix expression";
	}
	else
	{
		element = stack[top];
		top--;
		return(element);
	}
}

int Isoperator(char Operator)
{
	if(Operator == '^' || Operator == '*' || Operator == '/' || Operator == '+' || Operator =='-')
	{
		return 1;
	}
	else
	{
	    return 0;
	}
}

int precedenceOfoperator(char Operator)
{
	if(Operator == '^')
	{
		return(3);
	}
	else if(Operator == '*' || Operator == '/')
	{
		return(2);
	}
	else if(Operator == '+' || Operator == '-')         
	{
		return(1);
	}
	else
	{
		return(0);
	}
}

void InfixToPostfix(char infix_exp[], char postfix_exp[])
{ 
	int i, j;
	char element;
	char x;

	push('(');                               
	strcat(infix_exp,")");                 

	i=0;
	j=0;
	element=infix_exp[i];         

	while(element != '\0')        
	{
		//if elemnt is small bracket then push into stack
		if(element == '(')
		{
			push(element);
		}
		
		//if elemnt is an operand then add it to postfix array
		
		else if( isdigit(element) || isalpha(element))
		{
			postfix_exp[j] = element;              
			j++;
		}
		
		//if elemnt is an operator then pop from stack and acc to precedence pop from stack and add it to postfix array 
		
		else if(Isoperator(element) == 1)        
		{
			x=pop();
			while(Isoperator(x) == 1 && precedenceOfoperator(x)>= precedenceOfoperator(element))
			{
				postfix_exp[j] = x;                  
				j++;
				x = pop();                       
			}
			push(x);
			
            push(element); 
			                
		}
		
		//if elemnt is ')" then pop from stackand add those elements to postfix array till we will not get another closing ')"
		else if(element == ')')         
		{
			x = pop();                   
			while(x != '(')                
			{
				postfix_exp[j] = x;
				j++;
				x = pop();
			}
		}
		else
		{ 
			cout<<"Invalid infix Expression.";
		}
		i++;


		element = infix_exp[i]; 
	}
	if(top>0)
	{
		 cout<<"\nInvalid infix Expression.\n";        
		
	}
    
	postfix_exp[j] = '\0'; 

}


int main()
{
	char Infix[SIZE], Postfix[SIZE];         

	cout<<"Enter Infix expression : ";
	cin>>Infix;

	InfixToPostfix(Infix,Postfix);                  
	cout<<"Postfix Expression: "<<Postfix;
                    
	return 0;
}


