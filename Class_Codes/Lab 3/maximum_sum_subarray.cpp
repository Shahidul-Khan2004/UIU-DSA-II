#include<iostream>
using namespace std;


int cross_sum_subarr(int arr[],int l,int mid, int h){

// mid->l : l_sum_max
//mid-> h : r_sum_max
//cross_sum = l_sum_max+r_sum_max

int l_sum = INT_MIN;
int r_sum = INT_MIN;

int sum=0;
// mid->l : l_sum_max
for(int i=mid;i>=l;i--){
   
    sum+=arr[i];
    l_sum=max(l_sum,sum);

}

//mid-> h : r_sum_max
sum=0;
for(int i=mid+1;i<=h;i++){
    sum+=arr[i];
    r_sum=max(r_sum,sum);
}

return l_sum+r_sum;



}


//maximum sum subarray

int max_sum_subarr(int arr[],int l, int h){

//base case
//when only one element is left
if(l==h){
    return arr[l];
}
//time comp: nlogn
//divide 

int mid = (l+h)/2;

int l_sum= max_sum_subarr(arr,l, mid); //8,2
int r_sum= max_sum_subarr(arr,mid+1,h);//5,3

int cross_sum = cross_sum_subarr(arr,l,mid,h); // 8,2,5,3

return max( max(l_sum,r_sum),cross_sum);


}


int main(){

    int arr[]={2, 3, -8, 7, -1, 2, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<max_sum_subarr(arr,0,n-1)<<endl;



}