
// Sorting 1
// Insertion sort
// Sorting an array using insertion sort
/*
 * @author- sarapapa
 * Date -
 *
 * Sorting 1
 * Insertion sort
 * Sorting an array using insertion sort
 *
 *
 * */

#include <iostream>
using namespace std;

void insertion_sort(int sort[],int n);      // function to sort the {sort} array passed to it having {total} elements

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
    //Passing the array to function {insertion_sort} to sort the array
    insertion_sort(sort,total);
    return 0;
}

void insertion_sort(int sort[],int total){

    // To sort the array using the insertion sort
    int temp;       // to store the value to put in sorted sublist
    int sublist;    // to determine position to break the array into 2 sublist i.e sorted sublist(left side) and unsorted sublist(right side)
    for(int i=1;i<total;i++){
        temp = sort[i];
        sublist = i-1;
        while (sublist >= 0 && sort[sublist] > temp){
            sort[sublist+1] = sort[sublist];
            sublist--;
        }
        sort[sublist+1] = temp;
    }

    // to display the sorted array
    cout<<"\nSorted Array is : \n";
    for(int i=0;i<total;i++){
        cout<<sort[i]<<" ";
    }
    cout<<"\n";
}