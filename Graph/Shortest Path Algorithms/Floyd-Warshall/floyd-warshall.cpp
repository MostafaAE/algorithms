#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <limits>
#include <random>
using namespace std;

const int OO = (int)1e6;

void print(const vector<vector<int>> &adjMatrix)
{
  int n = adjMatrix.size();

  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      if (adjMatrix[i][j] >= OO)
        cout << "OO"
             << " ";
      else
        cout << adjMatrix[i][j] << " ";
    }
    cout << "\n";
  }
  cout << "**************************\n";
}

void floyd(vector<vector<int>> &adjMatrix)
{
  int n = adjMatrix.size();

  cout << "Input matrix\n";
  print(adjMatrix);

  for (int k = 0; k < n; ++k)
  {
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
      {
        int relax = adjMatrix[i][k] + adjMatrix[k][j]; // assume 2*OO fits in int
        adjMatrix[i][j] = min(adjMatrix[i][j], relax);
      }
    cout << "After relaxing with " << k << "\n";
    print(adjMatrix);
  }
}

void read_graph(vector<vector<int>> &adjMatrix)
{
  int n, m; // nodes and edges;
  cin >> n >> m;

  // Initialize all to OO
  adjMatrix = vector<vector<int>>(n, vector<int>(n, OO));

  for (int i = 0; i < n; ++i)
    adjMatrix[i][i] = 0; // set self loop = 0

  for (int i = 0; i < m; ++i)
  {
    int from, to, weight;
    cin >> from >> to >> weight; // 0-based
    if (from == to)
      continue; // let's ignore even if -ve
    adjMatrix[from][to] = min(adjMatrix[from][to], weight);
  }
}

int main()
{
  // freopen("data.txt", "rt", stdin);

  vector<vector<int>> adjMatrix;

  read_graph(adjMatrix);
  floyd(adjMatrix);

  return 0;
}

/*

5 12
0 1 5
0 1 9
0 3 2
1 2 2
1 1 7
2 0 3
2 4 7
3 2 4
3 4 1
4 0 1
4 1 8
4 1 3





Input matrix
0 5 OO 2 OO
OO 0 2 OO OO
3 OO 0 OO 7
OO OO 4 0 1
1 3 OO OO 0
**************************
After relaxing with 0
0 5 OO 2 OO
OO 0 2 OO OO
3 8 0 5 7
OO OO 4 0 1
1 3 OO 3 0
**************************
After relaxing with 1
0 5 7 2 OO
OO 0 2 OO OO
3 8 0 5 7
OO OO 4 0 1
1 3 5 3 0
**************************
After relaxing with 2
0 5 7 2 14
5 0 2 7 9
3 8 0 5 7
7 12 4 0 1
1 3 5 3 0
**************************
After relaxing with 3
0 5 6 2 3
5 0 2 7 8
3 8 0 5 6
7 12 4 0 1
1 3 5 3 0
**************************
After relaxing with 4
0 5 6 2 3
5 0 2 7 8
3 8 0 5 6
2 4 4 0 1
1 3 5 3 0
**************************

 */
