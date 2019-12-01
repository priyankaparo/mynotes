#include<iostream>
using namespace std;

//tower of HANOI function 
void TowerOfHanoi(int TotalDisks,char Source, char Auxiliary, char Destination)
{ 
//if disk no is only one
	if(TotalDisks==1)
	{
		cout<<"Move Disk "<<TotalDisks<<" from "<<Source<<" to "<<Destination<<endl;
		
		return ;
	}
	//to move disks from source tower to destination and auxiliary tower
	TowerOfHanoi(TotalDisks-1,Source,Destination,Auxiliary);
	
	cout<<"Move Disk "<<TotalDisks<<" from "<<Source<<" to "<<Destination<<endl;
	
//to move disks from auxiliary tower to destination and source tower

	TowerOfHanoi(TotalDisks-1,Auxiliary,Source,Destination);
}


int main()
{ 
	int n;
	
	cout<<"Enter no. of disks:";	
	cin>>n;
	
     TowerOfHanoi(n,'X','Y','Z');

	return 0;
}


