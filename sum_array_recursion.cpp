
#include <iostream>

using namespace std;

int sum_array(int n,int arr[])
{
    if(n==0) return 0;
    if(n==1) return arr[0];

    if(n>1)
        return arr[0]+sum_array(n-1,arr+1);

    }
int main()
{
    int arr[]= {2,2,2,2,2};
  int output = sum_array(5,arr);
         cout<<output;
    return 0;
}

