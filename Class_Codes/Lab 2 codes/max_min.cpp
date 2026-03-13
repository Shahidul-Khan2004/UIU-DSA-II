#include<iostream>
#include<utility>
#include<vector>
using namespace std;

pair<int,int> max_min_div(int arr[],int l, int h){

//base case : we've one element
if(l==h){
return {arr[l],arr[h]};

}

//divide the array

int mid = (l+h)/2;

pair<int,int> left_res = max_min_div(arr,l,mid);
pair<int,int> right_res = max_min_div(arr,mid+1,h);

//conquer
 pair<int,int> res;
 //max element
 res.first = max(left_res.first,right_res.first);
  //min element
res.second= min(left_res.second,right_res.second);

return res;

}


// find max and min element of a vector of int using recursion

pair<int,int> max_min( vector<int> v, int idx ){

//base case

//when only one element is left
if(idx == 0){
    return {v[idx],v[idx]};
}

//idx=5 -? idx=4
pair<int,int> res = max_min(v,idx-1);

return { max(v[idx], res.first) , min(v[idx],res.second) };                    }






int main(){

vector<int> v ={1,10, -1, 14,5};

pair<int,int> res = max_min(v, v.size()-1);

cout<< "max: "<<res.first<<" "<<"min: "<<res.second<<endl;

int arr[] = {1,10, -1, 14,5};

int n = sizeof(arr)/sizeof(arr[0]);
pair<int,int> res_div = max_min_div(arr,0,n-1);
cout<< "max: "<<res_div.first<<" "<<"min: "<<res_div.second<<endl;

}
