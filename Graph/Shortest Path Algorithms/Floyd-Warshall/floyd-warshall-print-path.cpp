#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <limits>
#include <random>
using namespace std;

/*

Create new 2D array path

Every time we relax (i, j) with node k
then path[i][j] = k

Now say I want to print path (i1, j1)
path[i1][j1] is k1
This means we go from i1 to k1
then from k1 to j1
So we can with 2 recursive calls print both sides


Extra
  Note, there is another way to do print the path
  Record on the path the previous node using prev[i][j] = prev[k][j]

  Now you can print path with a single recursive call: printPath(i, prev[i][j])

  We will see an example for that in BellmanFord algorithm


 */

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

void floyd(vector<vector<int>> &adjMatrix, vector<vector<int>> &path)
{
  int n = adjMatrix.size();

  for (int k = 0; k < n; ++k)
  {
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
      {
        int relax = adjMatrix[i][k] + adjMatrix[k][j]; // assume 2*OO fits in int
        if (adjMatrix[i][j] > relax)
        {
          adjMatrix[i][j] = relax;
          path[i][j] = k;
        }
      }
  }
}

int read_graph(vector<vector<int>> &adjMatrix)
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
  return n;
}

void build_path(int src, int dest, vector<vector<int>> &path)
{
  if (path[src][dest] == -1)
  { // So this is the last way
    cout << src << " " << dest << "\n";
    return;
  }
  build_path(src, path[src][dest], path);
  build_path(path[src][dest], dest, path);
}

int main()
{
  // freopen("data.txt", "rt", stdin);

  vector<vector<int>> adjMatrix;

  int n = read_graph(adjMatrix);

  // -1 for direct link
  vector<vector<int>> path(n, vector<int>(n, -1));

  floyd(adjMatrix, path);
  print(adjMatrix);

  build_path(0, 4, path);

  return 0;
}

/*
5 5
0 1 1
1 2 2
2 3 3
3 4 4
0 4 15


0 1 3 6 10
OO 0 2 5 9
OO OO 0 3 7
OO OO OO 0 4
OO OO OO OO 0
**************************
0 1
1 2
2 3
3 4

 */
