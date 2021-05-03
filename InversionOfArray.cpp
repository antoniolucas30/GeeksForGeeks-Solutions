
  // } Driver Code Ends

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to find inversion count in the array

// arr[]: Input Array
// N : Size of the Array arr[]

long long mergeFcn(long long arr[], long long leftIndex, long long middleIndex, long long rightIndex){

  long long* vec = new long long[rightIndex - leftIndex + 1], changeLeft = leftIndex, changeRight = middleIndex + 1, currentIndex = 0, countInversions = 0;

  while((changeLeft <= middleIndex) && (changeRight <= rightIndex)){

    if(arr[changeLeft] <= arr[changeRight])
      vec[currentIndex++] = arr[changeLeft++];

    else{

      vec[currentIndex++] = arr[changeRight++];
      countInversions += (middleIndex - changeLeft) + 1;

    }

  }

  while(changeLeft <= middleIndex)
    vec[currentIndex++] = arr[changeLeft++];

  while(changeRight <= rightIndex)
    vec[currentIndex++] = arr[changeRight++];

  for(long long i = 0, j = leftIndex; j <= rightIndex; i++, j++)
    arr[j] = vec[i];

  delete[] vec;

  return countInversions;

}

long long mergeSort(long long arr[], long long leftIndex, long long rightIndex){

  long long middle, countInversions = 0;

  if(leftIndex < rightIndex){

    middle = (leftIndex + rightIndex) / 2;

    countInversions += mergeSort(arr, leftIndex, middle);
    countInversions += mergeSort(arr, middle + 1, rightIndex);

    countInversions += mergeFcn(arr, leftIndex, middle, rightIndex);

  }

  return countInversions;

}

long long int inversionCount(long long arr[], long long N)
{
    // Your Code Here

    return mergeSort(arr, 0, (N - 1));
}


// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        
        cout << inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends
