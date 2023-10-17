#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <limits>
#include <random>
using namespace std;



/*

We can use a similar logic from Floyd

For 2 nodes (i, j): we need to count paths that use/don't use node k (for each k)

If we have M paths from i to k and N paths from k to j,
	then we have more NM paths from i to j

This all assumes no cycles happens, hence paths are simple

How can we find pairs that have infinite paths between them?

First, how can we know a node has a cycle passing with it?
If after applying Floyd, graph[k][k] > 0
	It means, there is a path from the node to itself (cycle)

Now assume pair (i1, j1) doesn't use k at all. This cycle has NO effect on it

But what if pair (i2, j2) use k [i2-k-j2]? then infinite paths here






More thoughts on correctness for the DP in-placement update

1- assume graph is DAG
	  k = 5, i = 1, j = 2 we will use adj[ 1 ][ 5 ] with old value
	  k = 5, i = 1, j = 5 we will update adj[ 1 ] [ 5 ]
	  k = 5, i = 1, j = 7 we will use adj[ 1 ][ 5 ] with new value
	  Won't this give and incorrect result?

	  NO. E.g. when k = 5, i = 1, j = 5:
	  	  adj[1][5] += adj[1][5] * adj[5][5];
	  	  adj[5][5] = 0, so no update happens.
	  	  	  In general, when k = i or j, no updates happens, so in-placement update is fine.

2-  What if graph is not DAG.
  if(adj[i][i] > 0)	-> i has a cycle path on it

  Generally, for any node v that has a cycle,
  		if i reaches v, and v reaches j, then count of (i, j) is useless as count is OO. Remain adj[][] is valid

*/


const int OO = (int) 1e6;

void print(const vector<vector<int>> &adjMatrix) {
	int n = adjMatrix.size();

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (adjMatrix[i][j] >= OO)
				cout << "OO" << " ";
			else
				cout << adjMatrix[i][j] << " ";
		}
		cout << "\n";
	}
}

void count_paths(vector<vector<int>> &graph) {
	int n = graph.size();

	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				graph[i][j] += graph[i][k] * graph[k][j];

	for (int k = 0; k < n; k++)
		if (graph[k][k])	// cycle
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					// if i-j path with k, then infinite paths
					if (graph[i][k] && graph[k][j])
						graph[i][j] = -1;
}

void read_graph(vector<vector<int>> &adjMatrix) {
	int n, m;	// nodes and edges;
	cin >> n >> m;

	adjMatrix = vector<vector<int>>(n, vector<int>(n, 0));

	for (int i = 0; i < m; ++i) {
		int from, to;
		cin >> from >> to;	// 0-based
		adjMatrix[from][to] += 1;	// add one more path
	}
}

int main() {
	//freopen("data.txt", "rt", stdin);

	vector<vector<int>> adjMatrix;

	read_graph(adjMatrix);
	count_paths(adjMatrix);
	print(adjMatrix);

	return 0;
}

/*
5 6
0 1
0 2
1 2
0 3
3 4
4 3

0 1 2 -1 -1
0 0 1 0 0
0 0 0 0 0
0 0 0 -1 -1
0 0 0 -1 -1

5 7
0 1
0 2
0 4
2 4
2 3
3 1
4 3

0 4 1 3 2
0 0 0 0 0
0 2 0 2 1
0 1 0 0 0
0 1 0 1 0

6 5
0 2
0 1
1 5
2 5
2 1

0 2 1 0 0 3
0 0 0 0 0 1
0 1 0 0 0 2
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0

5 9
0 1
0 2
0 3
0 4
1 4
2 1
2 0
3 0
3 1

-1 -1 -1 -1 -1
0 0 0 0 1
-1 -1 -1 -1 -1
-1 -1 -1 -1 -1
0 0 0 0 0

 */

