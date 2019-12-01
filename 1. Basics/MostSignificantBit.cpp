#include <bits/stdc++.h> 
using namespace std; 
  
int main() 
{ 
    int num,pos;
    cout<<"enter the number: ";
    cin>>num;

// To find the position of the most significant set bit 
    pos = (int)(log2(num));

// take the power of that position to get msb number  
    cout << (((int)(pow(2, pos)))); 
    return 0; 
} 


