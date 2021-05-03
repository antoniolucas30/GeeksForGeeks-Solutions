#include <bits/stdc++.h>
using namespace std;

#define MAX 5
vector<string> printPath(int m[MAX][MAX], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int m[MAX][MAX];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }

        vector<string> result = printPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}

void FuncBacktrack(std::vector <std::string>& vecPaths, std::string currentString, bool nodeInPath[MAX][MAX], int currentI, int currentJ, int total, int m[MAX][MAX]){

  int moveI[] = {0, 0, 1, -1};
  int moveJ[] = {-1, 1, 0, 0};
  char direction;

  if(currentI == (total - 1) && currentJ == (total - 1))
    vecPaths.push_back(currentString);

  nodeInPath[currentI][currentJ] = 1;

  for(int i = 0; i < 4; i++){

    direction = (i == 0) ? 'L' : (i == 1) ? 'R' : (i == 2) ? 'D' : 'U';

    if(currentI + moveI[i] < total && currentI + moveI[i] >= 0 && currentJ + moveJ[i] < total && currentJ + moveJ[i] >= 0 && nodeInPath[currentI + moveI[i]][currentJ + moveJ[i]] == 0 && m[currentI + moveI[i]][currentJ + moveJ[i]] == 1){

      FuncBacktrack(vecPaths, (currentString + direction), nodeInPath, currentI + moveI[i], currentJ + moveJ[i], total, m);

    }

  }

  nodeInPath[currentI][currentJ] = 0;

}

vector<string> printPath(int m[MAX][MAX], int n) {

  std::string currentString = "";
  std::vector <std::string> Paths;
  bool nodeInPath[MAX][MAX] = {0};

  if(m[0][0] == 1 && m[n - 1][n - 1] == 1)
    FuncBacktrack(Paths, currentString, nodeInPath, 0, 0, n, m);

  std::sort(Paths.begin(), Paths.end());

  return Paths;

}
