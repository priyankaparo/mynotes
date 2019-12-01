#include<iostream>
using namespace std;

int FindNumber(int R, int C , int *mat) 

{ 
    int p;
    cout<<"enter unknown elemnt: ";
	cin>>p;
    int count=0;
	int row = 0; 
	int col = C-1; 
	//statrting searching elemnt from row=0 and last col
	while (row <R && col >= 0) 
	{
		//if found elemnt in row and col then print
	   if (*((mat+row*C) + col) == p)
	    { 
	      count =1;
		  cout<<"found at index: [" <<row<<"]["<<col<<"]";
		  break;
	     } 
	     
	    //if element is less than col ele then decrease column and traverse in same row
	   else if (*((mat+row*C) + col) > p) 
	     { 
	        col--; 
	      }
	      
	     //else increase row and traverse in same col
	      
	    else 
	        {  
	           row++; 
	        } 
	  }
	  
	 return count;
 }
 int main()
 {
 	int k,i,j,R,C;
 	cout<<"enter no of rows: ";
 	cin>>R;
 	cout<<"enter no of cols: ";
 	cin>>C;
	cout<<"enter matrix elemnt acc to sorted cols and rows: ";
	int a[R][C];
	for(i=0;i<R;i++)
	{
		for(j=0;j<C;j++)
		{
			cin>>a[i][j];
		}
	}
	cout<<"entered sorted matrix is: \n";
	for(i=0;i<R;i++)
	{
		for(j=0;j<C;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<"\n";
	}
//function to find number in sorted matrix;
    k = FindNumber(R ,C ,&a[0][0]);
    if(k==0)
    {
     cout<<"not found.";
    }
	
 }



