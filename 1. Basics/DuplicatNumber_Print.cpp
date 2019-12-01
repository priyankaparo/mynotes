#include <iostream> 
using namespace std; 
  
int main() 
{ 
    int len;
    int A[len],i; 
    cout<<"enter the size of array: ";
    cin>>len;
    cout<<"enter the elements of array: ";
    for(i=0;i<len;i++)
    {
       cin>>A[i];
    }
    cout << "The repeating elements are: \n"; 
    
    // firstly take modulus of array elements wiht respect to length of array then add len to that       // position index element

    for (int i = 0; i < len; i++) 
    { 
        int pos = A[i] % len; 
        A[pos] += len; 
    } 
  
    // check which value exists more than 1 by dividing with the size of array 
    
for (int i = 0; i < len; i++) 
    { 
        if ((A[i]/len) > 1) 
            cout << i << " "; 
    } 
    return 0; 
} 


