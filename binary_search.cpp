#include <iostream>
using namespace std;
int binarysearch(int a[],int n,int item){
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(a[mid]==item)
           return mid;
        else if(a[mid]<item)
            low=mid+1;
        else high=mid-1;
    }
    return -1;
}
int main()
{;
   int a[5]={1,2,4,5,6};
    cout<<binarysearch(a,5,4)<<endl;
    return 0;
}
