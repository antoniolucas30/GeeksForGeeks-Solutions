// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Returns the maximum value that  
// can be put in a knapsack of capacity W 

int realKnapSack(int** matrix, int currentCapacity, int wt[], int val[], int currentIndex, int maxLen){

  int temporaryPut, temporaryDontPut;

  if(matrix[currentIndex][currentCapacity] != -1)
    return matrix[currentIndex][currentCapacity];

  if(currentIndex == maxLen || currentCapacity == 0)
    return matrix[currentIndex][currentCapacity] = 0;

  temporaryDontPut = realKnapSack(matrix, currentCapacity, wt, val, currentIndex + 1, maxLen);

  if(wt[currentIndex] <= currentCapacity){

    temporaryPut = val[currentIndex] + realKnapSack(matrix, currentCapacity - wt[currentIndex], wt, val, currentIndex + 1, maxLen);

    return matrix[currentIndex][currentCapacity] = std::max(temporaryPut, temporaryDontPut);

  }

  return matrix[currentIndex][currentCapacity] = temporaryDontPut;

}

int knapSack(int W, int wt[], int val[], int n) 
{ 
   // Your code here

  int**matrix = new int*[n + 1], result;

  for(int i = 0; i < n + 1; i++){
    
    matrix[i] = new int[W + 1];
    
    for(int j = 0; j < W + 1; j++)
      matrix[i][j] = -1;

  }

  result = realKnapSack(matrix, W, wt, val, 0, n);

  for(int i = 0; i < n + 1; i++)
    delete[] matrix[i];

  delete[] matrix;

  return result;
}





// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        
        //calling method knapSack()
        cout<<knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends
