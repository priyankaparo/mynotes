#include<iostream>
using namespace std;

void Ispalindrome(int n) 
{
   int reverse_num=0,val;
   val = n;
   // calculate the reverse number of that number using modulus and then adding into multiplier of 10;
   while(n > 0) 
   { 
      reverse_num = reverse_num * 10 + n % 10; 
      n = n / 10; 
   } 

   if(val==reverse_num)
      cout<<val<<" is a palindrome number"<<endl;
   else 
      cout<<val<<" is not a palindrome number"<<endl;    
}

int main() 
{ 
    int number;
    cout<<"Enter the number: ";
    cin>>number;
    
    Ispalindrome(number);
    
    return 0;
} 


