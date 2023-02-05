#include <iostream>

using namespace std;
int maxi=0;
void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
int partition(int arr[], int low, int high)
{
    int pivot=arr[high];
    int x=(low-1);
    for(int j=low; j<=high-1; j++)
    {
        if(arr[j]<pivot)
        {
            x++;
            swap(&arr[x],&arr[j]);
        }
    }
    swap(&arr[x+1],&arr[high]); //To get the pivot in the middle of the list

    return (x+1);
}
void quickSort(int arr[],int low,int high)
{
    if (low > high) return;


    int pivot_pos = partition(arr, low, high);  //Now the list is -> (elements < pivot) + pivot + (elements > pivot)

    // quick sort elements < pivot
    quickSort(arr, low, pivot_pos - 1);

    // quick sort elements > pivot
    quickSort(arr, pivot_pos + 1, high);
}
int main()
{
    int arr[]= {1,5,7,2,6,3,8,5};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr,0,n-1);
    for(int e:arr)
    {
        cout<<e<<" ";
    }
    return 0;
}
