#include <iostream>
#include <climits>
using namespace std;

int Max_Subarray_Product(int arr[], int n) {
    int maxProd = arr[0];
    int minProd = arr[0];
    int result = arr[0];
    for(int i =1;i<n;i++){
        if(arr[i]<0){
            swap(maxProd,minProd);
        }
        maxProd = max(arr[i],maxProd*arr[i]);
        minProd = min(arr[i],minProd*arr[i]);
        result =  max(result,maxProd);
    }
    return result;

}