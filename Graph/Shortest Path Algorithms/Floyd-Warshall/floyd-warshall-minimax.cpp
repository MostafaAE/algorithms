#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <limits>
#include <random>
#include <cstring>
using namespace std;

const int OO = (int)1e6;

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

void compute_min_max(vector<vector<int>> &graph)
{
  int n = graph.size();

  for (int k = 0; k < n; ++k)
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        graph[i][j] = min(graph[i][j], max(graph[i][k], graph[k][j]));
}

void print_matrix(vector<vector<int>> &graph)
{
  int n = graph.size();
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (j)
        putchar(' ');
      if (graph[i][j] >= OO)
        printf("OO");
      else
        printf("%d", graph[i][j]);
    }
    puts("");
  }
}

int main()
{
  // freopen("data.txt", "rt", stdin);

  vector<vector<int>> adjMatrix;

  read_graph(adjMatrix);
  compute_min_max(adjMatrix);
  print_matrix(adjMatrix);

  return 0;
}

/*

5 8
0 1 9
0 2 5
0 4 4
1 2 2
2 4 1
2 3 6
3 1 3
4 3 12


0 6 5 6 4
OO 0 2 6 2
OO 6 0 6 1
OO 3 3 0 3
OO 12 12 12 0

 */
