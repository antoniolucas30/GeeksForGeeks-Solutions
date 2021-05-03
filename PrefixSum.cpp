#include <iostream>

struct Node{

  long indexEsquerda, indexDireita;

  struct Node *filhoEsquerda, *filhoDireita;

  long max, prefix;

  void Destruction(struct Node *currentNode){

    std::cout << "ENTREI" << std::endl;

    if(currentNode->filhoEsquerda != NULL)
      Destruction(currentNode->filhoEsquerda);
    
    if(currentNode->filhoDireita != NULL)
      Destruction(currentNode->filhoDireita);

    delete currentNode->filhoEsquerda;
    delete currentNode->filhoDireita;

  }

  struct Node *constructor(long* vec, int startIndex, int endIndex){

    struct Node *nodeAtual = new Node;
    int middleIndex = (startIndex + endIndex) / 2;

    nodeAtual->indexEsquerda = startIndex;
    nodeAtual->indexDireita = endIndex;

    if(startIndex == endIndex){

      nodeAtual->filhoEsquerda = NULL;
      nodeAtual->filhoDireita = NULL;

      nodeAtual->max = vec[startIndex];
      nodeAtual->prefix = vec[startIndex];

    }

    else{

      nodeAtual->filhoEsquerda = constructor(vec, startIndex, middleIndex);
      nodeAtual->filhoDireita = constructor(vec, middleIndex + 1, endIndex);

      nodeAtual->max = nodeAtual->filhoEsquerda->max + nodeAtual->filhoDireita->max;
      nodeAtual->prefix = std::max(nodeAtual->filhoEsquerda->prefix, nodeAtual->filhoEsquerda->max + nodeAtual->filhoDireita->prefix);

    }
  
    return nodeAtual;

  }

  long Search(struct Node *currentNode, int indexLeft, int indexRight){

    if(indexLeft > currentNode->indexDireita || indexRight < currentNode->indexEsquerda)
      return 0;

    else if(indexLeft <= currentNode->indexEsquerda && indexRight >= currentNode->indexDireita)
      return currentNode->max;

    else{

      return (Search(currentNode->filhoEsquerda, indexLeft, indexRight) + Search(currentNode->filhoDireita, indexLeft, indexRight));

    }

  }


};

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int testCases, lenVec, lenPairs, indexStart, indexEnd, num;
  struct Node *noRaiz;
  long* vec;

  std::cin >> testCases;

  for(int i = 0; i < testCases; i++){

    std::cin >> lenVec >> lenPairs;

    vec = new long[lenVec]{0};

    for(int i = 0; i < lenVec; i++){

      std::cin >> num;
      
      vec[i] = num;

    }

    noRaiz = noRaiz->constructor(vec, 0, (lenVec - 1));

    for(int i = 0; i < lenPairs; i++){

      std::cin >> indexStart >> indexEnd;

      if(i != 0)
        std::cout << ' ';

      std::cout << noRaiz->Search(noRaiz, indexStart, indexEnd);

    }

    std::cout << std::endl;;

    //noRaiz->Destruction(noRaiz);
    delete noRaiz;
    delete[] vec;

  }

  return 0;
}
