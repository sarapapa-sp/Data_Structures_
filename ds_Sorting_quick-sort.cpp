/*
 * @author- sarapapa
 * Date -
 *
 * Sorting 2
 * Quick sort
 * Sorting an array using Quick sort
 *
 *
 * */

#include <iostream>
using namespace std;

void quick_sort(int sort[],int low,int high);
int partition (int arr[], int low, int high);    // to find center element
void swap(int* a, int* b)                        // swap the elements
{
    int t = *a;
    *a = *b;
    *b = t;
}


int main(){
    //Reading the total numbers in array from user
    int total;
    cout<<"Enter the total numbers in the array : ";
    cin>>total;

    //reading the {total} numbers from the user and storing in the array
    int sort[total];
    cout<<"Enter the "<<total<<" elements :";
    for(int i=0;i<total;i++){
        cin>>sort[i];
    }
    cout<<"Added";
    //Passing the array to function {} to sort the array
    quick_sort(sort,0,total-1);

    // to display the sorted array
    cout<<"\nSorted Array is : \n";
    for(int i=0;i<total;i++){
        cout<<sort[i]<<" ";
    }
    cout<<"\n";
    return 0;
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quick_sort(int sort[],int low,int high){
    int loc;
    if(low<high){
         loc = partition(sort,low,high);
         quick_sort(sort,low,loc-1);
         quick_sort(sort,loc+1,high);
     }
}