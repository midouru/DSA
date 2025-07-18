/*TO CALCULATE MAXIMUM SUBARRAY SUM WE USE KADANE'S ALGORITHM ITS THE OPTIMIZED APPROACH TO SOLVE THE PROBLEM*/

#include <iostream>
#include <climits>
using namespace std;

int max_sub_Sum(int arr[], int n){
    int maxSum = INT_MIN;
    int currSum = 0;
    
    for(int i=0;i<n;i++){
        currSum = currSum + arr[i];
        maxSum = max(currSum,maxSum);
         
        if(currSum < 0){
            currSum = 0;
        }
        
    }
    return maxSum;

}