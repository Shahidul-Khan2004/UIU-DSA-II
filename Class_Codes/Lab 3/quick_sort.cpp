#include<iostream>
using namespace std;


int partition(int arr[],int l,int h){
    
    int mid=(l+h)/2;
    swap(arr[mid],arr[h]);

    int i = l; //finds greater elements than pivot
    int j =h-1; // finds smaller elements than pivot
    int pivot = arr[h];
    
    while(i<=j){
        while( i<=j && arr[i]<=pivot ){
            i++;
        }
        while(i<=j && arr[j]>=pivot ){
            j--;
        }
        if(i<j){
            swap(arr[i],arr[j]);
        }
    }

    swap(arr[h],arr[j+1]);

    return j+1;


}

void quicksort(int arr[],int l, int h){

    if(l<h){

    int pivot_idx = partition(arr,l,h);

    quicksort(arr,l,pivot_idx-1);
    quicksort(arr,pivot_idx+1,h);

    }
   
}


int main(){


int arr[]={10, 7, 8, 9, 1, 5};
quicksort(arr,0,5);
for(int x:arr){
    cout<<x<<endl;
}


}