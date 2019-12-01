
// NOTE: we can use the concept of MSB Bit number and just adding one extra bit because 
// bit number starts from 0 index

#include <bits/stdc++.h> 
using namespace std; 
  
int main() 
{ 
    int num,pos;
    cout<<"enter the number: ";
    cin>>num;

// To find the position of the most significant set bit 

    pos = (int)(log2(num));

// then adding 1 more bit to that position ,will give the number of bits required for that num 
 
    cout << (pos+1); 
    return 0; 
} 


