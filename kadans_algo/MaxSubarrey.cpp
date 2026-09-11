#include<iostream>
using namespace std;
int MaxSubarrey(int arr[] , int n){
    int best_ending = arr[0];
    int ans = arr[0];
    for( int i =1; i<n; i++){
    int v1 = best_ending +arr[i];
    int v2 = arr[i];
    best_ending = max(v1,v2);
   ans = max(ans , best_ending);
    }
    return ans;
}
int main(){
    int arr[5]={1,-4,3,1,5};
    int n =5;
  int result = MaxSubarrey(arr,n);
  cout<<"The maximum subarrey sum is : "<<result;
}