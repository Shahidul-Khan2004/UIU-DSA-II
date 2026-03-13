
#include<iostream>
#include<utility>
#include<vector>
using namespace std;

void merge_arrays(int arr[], int l, int mid, int h){

int merged[h-l+1];

int i = l; // to access the first half : l->mid
int j = mid+1; // to access the second half : mid+1->h

int k = 0;

while(i<=mid && j<=h){

    if(arr[i]<=arr[j]){
      merged[k] = arr[i];
      i++;
      k++;
    }
     else if(arr[i]>arr[j]){
      merged[k] = arr[j];
      j++;
      k++;
    }


}

while(i<=mid){
    merged[k]=arr[i];
    i++;
    k++;
}

while(j<=h){
    merged[k]=arr[j];
    j++;
    k++;
}
k =0;

for(int i =l;i<=h;i++){
    arr[i]= merged[k];
    k++;
}




}




void merge_sort(int arr[],int l , int h){


//base case

if(l==h){
    return;
}

int mid = (l+h)/2;

merge_sort(arr, l, mid); //st:l , en : mid
merge_sort(arr, mid+1,h); // st: mid+1 , en: h

merge_arrays(arr, l, mid, h );





}



int main(){


int arr[]={14, 15, -1,4, 10,2};
int n = sizeof(arr)/sizeof(arr[0]);

merge_sort(arr,0,n-1);

for( int x: arr){
    cout<<x << endl;
}



}
