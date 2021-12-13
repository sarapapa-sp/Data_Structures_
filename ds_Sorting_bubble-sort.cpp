/*
 * @author- sarapapa
 * Date -
 *
 * Sorting
 * Bubble sort (Optimised bubble sort Algorithm)
 * Sorting an array using bubble sort
 *
 *
 * */
#include <iostream>
using namespace std;

void bubble_sort(int sort[],int n);      // function to sort the {sort} array passed to it having {total} elements

int main(){

    cout<<"Implementing Bubble sort\n";
    //Reading the total numbers in array from user
    int total;
    cout<<"Enter the total numbers in the array :";
    cin>>total;

    //reading the {total} numbers from the user and storing in the array
    int sort[total];
    cout<<"Enter the "<<total<<" elements :";
    for(int i=0;i<total;i++){
        cin>>sort[i];
    }
    //Passing the array to function {insertion_sort} to sort the array
    bubble_sort(sort,total);

    // to display the sorted array
    cout<<"\nSorted Array is : \n";
    for(int i=0;i<total;i++){
        cout<<sort[i]<<" ";
    }
    cout<<"\n";
    return 0;
}
// Implementing Optimised Bubble sort algo
void bubble_sort(int sort[],int n){
    int temp;               // to swap the elements
    for(int i=0;i<n-1;i++){
        int flag=0;         // to check if swapping takes place in 2nd loop
        for(int j=0;j<n-1-i;j++){
            if(sort[j]>sort[j+1]){
                // Swapping sort[j] and sort[j+1] using temp
                temp=sort[j];
                sort[j]=sort[j+1];
                sort[j+1]=temp;
                flag=1;
            }
        }
        if(flag==0)
            break;
    }
}