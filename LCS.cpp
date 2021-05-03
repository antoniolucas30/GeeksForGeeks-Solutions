// { Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

int lcs(int, int, string, string);

int main()
{
    int t,n,k,x,y;
    
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        
        cout << lcs(x, y, s1, s2) << endl;
    }
    return 0;
}
// } Driver Code Ends


// function to find longest common subsequence

int realLCS(int** DP, int indexS1, int indexS2, string S1, string S2){

  int result, tmp1, tmp2;

  if(indexS1 < 0 || indexS2 < 0)
    return 0;

  if(DP[indexS1][indexS2] != -1)
    return DP[indexS1][indexS2];

  if(S1[indexS1] == S2[indexS2])
    result = 1 + realLCS(DP, indexS1 - 1, indexS2 - 1, S1, S2);

  else{

    tmp1 = realLCS(DP, indexS1 - 1, indexS2, S1, S2);
    tmp2 = realLCS(DP, indexS1, indexS2 - 1, S1, S2);

    result = std::max(tmp1, tmp2);

  }

  DP[indexS1][indexS2] = result;

  return DP[indexS1][indexS2];

}

int lcs(int x, int y, string s1, string s2){
    
    int** DP = new int*[x];

    for(int i = 0; i < x; i++){

      DP[i] = new int[y];

      for(int j = 0; j < y; j++)
        DP[i][j] = -1;

    }

    return realLCS(DP, x - 1, y - 1, s1, s2); 
    
}
