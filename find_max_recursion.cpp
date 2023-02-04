#include <iostream>

using namespace std;
int maxi=0;
int find_maximum(int n,int arr[],int maxi)
{

    if(n==1) return arr[0];

    if(arr[0]>maxi) maxi=arr[0];

        return find_maximum(n-1,arr+1,maxi);

    }
int main()
{
    int arr[]= {2,2,2,2,3};
  int output = find_maximum(5,arr,maxi);
         cout<<output;
    return 0;
}

