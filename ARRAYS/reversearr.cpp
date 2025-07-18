#include <iostream>
#include <algorithm>
using namespace std;

void reverse(int arr[], int n){
    int start = 0;
    int end = n - 1;
    while(start<end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
    for(int i=0;i<n;i++){
        cout << arr[i];
    }
    
}

int main(){
    int arr[20];
    int n;
    cout << "Enter size of array : ";
    cin >> n;
    cout << "Enter array elements : ";
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    cout << "Array elements : ";
    for(int i=0;i<n;i++){
        cout << arr[i];
    }
    cout << "Array after reverse : ";
    reverse(arr,n);
    
    

}