#include<iostream>
#include <unordered_map> 
using namespace std;

bool findsum(int arr[], int n)
{
    unordered_map<int,bool> sumMap;
 
    // Traverse throught array and store prefix sums
    int sum = 0;
    for (int i = 0 ; i < n ; i++)
    {
        sum += arr[i];
 
        // If prefix sum is 0 or it is already present
        if (sum == 0 || sumMap[sum] == true)
            return true;
 
        sumMap[sum] = true;
    }
    return false;
}
int main() 
{
    
    int t;
	cin>>t;
	for(int ti=1;ti<=t;ti++)
	{
	    int n;
	    cin>>n;
	    int *a=new int[n];
	    
	    for(int i=0;i<n;i++)
	    {
	        int n1;
	        cin>>n1;
	        a[i]=n1;
	    }
	    
	    if(findsum(a,n))
	    cout<<"Yes"<<"\n";
	    else
	    cout<<"No"<<"\n";
	}
	return 0;
}



