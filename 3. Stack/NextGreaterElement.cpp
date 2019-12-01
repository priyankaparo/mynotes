#include<iostream> 

using namespace std;

#define MAXSIZE 100 
  
// created a stack structure 
struct stack 
{ 
    int top; 
    int items[MAXSIZE]; 
}; 
  
// PUSH function for stack 
void push(struct stack *ps, int x) 
{ 
    if (ps->top == MAXSIZE-1) 
    { 
        cout<<"stack overflow" ;
        
    } 
    else
    { 
        ps->top += 1; 
        int top = ps->top; 
        ps->items [top] = x; 
    } 
} 
  
  // emptycheck function for stack
bool isEmpty(struct stack *ps) 
{ 
    return (ps->top == -1)? true : false; 
} 
 
 // pop function for stack 
int pop(struct stack *ps) 
{ 
    int temp; 
    if (ps->top == -1) 
    { 
        cout<<"stack underflow";
        
    } 
    else
    { 
        int top = ps->top; 
        temp = ps->items [top]; 
        ps->top -= 1; 
        return temp; 
    } 
} 
  
/* prints next larger element of that array elemnt */
void NextElement(int arr[], int n) 
{ 
    int i = 0; 
    struct stack s; 
    s.top = -1; 
    int poppedelement, next; 
  
    // push the first element to stack
    push(&s, arr[0]); 
  
    // iterate for rest of the elements 
    for (i=1; i<n; i++) 
    { 
        next = arr[i]; 
  
        if (isEmpty(&s) == false) 
        { 
            // if stack is not empty, then pop an element from stack 
            poppedelement = pop(&s); 
  
            /* If the popped element is smaller than next then print the pair 
                & keep popping while elements are smaller and 
                stack is not empty */
            while (poppedelement < next) 
            { 
               cout<<poppedelement<<" "<<next<<endl;
                if(isEmpty(&s) == true) 
                   break; 
                poppedelement = pop(&s); 
            } 
  
            /* If element is greater than next, then push 
               the element back */

            if (poppedelement > next) 
                push(&s, poppedelement); 
        } 
  
      
  /* push next to stack so that we can find 
           next greater for it */
        push(&s, next); 
    } 
  
    /* After iterating over the loop, the remaining 
       elements in stack do not have the next greater 
       element, so print -1 for them */
    while (isEmpty(&s) == false) 
    { 
        poppedelement = pop(&s); 
        next = -1; 
        cout<<poppedelement<<" "<<next<<endl;
    } 
} 
  

int main() 
{ 
    int n,i;
    cout<<"enter the size of array: ";
    cin>>n;
    cout<<"enter the elements of array: ";
    int arr[n]; 
    for(i=0;i<n;i++)
    {
    	cin>>arr[i];
	}
    
    cout<<"corresponding next larger elemnt :  ";

    NextElement(arr, n); 
    
    return 0; 
} 


