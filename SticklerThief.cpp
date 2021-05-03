#include <iostream>

long* DP;

long KnapsackModified(int* vec, int currentIndex, int lenVec);

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int lenVec, testCases, *vec;
  long tamDP;

  std::cin >> testCases;

  for(int i = 0; i < testCases; i++){

    tamDP = 0;

    std::cin >> lenVec;

    vec = new int[lenVec], DP = new long[lenVec];

    for(int j = 0; j < lenVec; j++){
      
      std::cin >> vec[j];
      DP[j] = -1;

    }

    std::cout << KnapsackModified(vec, 0, lenVec) << std::endl;

    delete[] vec; delete[] DP;

  }

  return 0;
}

long KnapsackModified(int* vec, int currentIndex, int lenVec){

  int tmpPut, tmpDontPut;

  if(currentIndex >= lenVec)
    return 0;

  if(DP[currentIndex] != -1)
    return DP[currentIndex];

  tmpDontPut = KnapsackModified(vec, currentIndex + 1, lenVec);
  tmpPut = vec[currentIndex] + KnapsackModified(vec, currentIndex + 2, lenVec);

  return (DP[currentIndex] = std::max(tmpDontPut, tmpPut));

}
