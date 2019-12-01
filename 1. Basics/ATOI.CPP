#include<iostream> 
#include<string.h>

using namespace std;

int conStringtonumber(char str[],int len)
{
  if(str== NULL )
   return 0;

  
  int integer_result=0, i =0 ;
  bool isPositive=true;
  int radix=10;
  //if strting index is + then no need to add or - then add - before to integerresult
  if (str[0] == '-') 
  {
   i++;
   isPositive = false;
  } 
  else if (str[0] == '+') 
  {

   i++;
  }
  
 // converting string to integer 
  while( (i<len )) 
    { 
     //if element is digit then
        if (isdigit(str[i])) 
            {
            	// k calculating integer value of string
            	int k=str[i]-'0';
            	
            	integer_result=k+ integer_result*radix;
            	i++;
			}
		//if element is not digit then	break the loop
        else
            break; 
    } 
		  
  
  if(!isPositive)
   integer_result=-integer_result;

  return integer_result;
  
 }     
   
    
int main()
{
	int size_ofstring;
	cout<<"enter the size of string: ";
	cin>>size_ofstring;
	cout<<"\nenterstring: ";
	char a[size_ofstring];
	
	cin>>a;
	//call function to convert string to number
	int k= conStringtonumber(a,size_ofstring);
	cout<<k;
	return 0;
}



