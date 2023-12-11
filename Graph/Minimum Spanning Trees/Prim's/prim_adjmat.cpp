#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <limits>
#include <random>
using namespace std;

const int OO = 2 * 1e6 * 1000; // careful from OO value

int MST(const vector<vector<int>> &adjMax, int src = 0)
{ // O(n^2)
	int n = adjMax.size();
	vector<bool> vis(n, 0);
	vector<int> dist(n, OO);
	dist[src] = 0;
	int mstCost = 0;

	while (true)
	{
		int val = OO, idx = -1;
		for (int i = 0; i < n; ++i)
			if (!vis[i] && dist[i] < val)
				val = dist[i], idx = i;
		if (idx == -1)
			break;

		mstCost += val;

		// Relax with the selected node
		for (int i = 0; i < n; ++i)
			if (dist[i] > adjMax[idx][i]) // the only change from Dijkstra
				dist[i] = adjMax[idx][i];

		vis[idx] = true; // delete
	}
	return mstCost;
}

void read_graph(vector<vector<int>> &adjMatrix)
{
	int n, m; // nodes and edges;
	cin >> n >> m;

	// Initialize all to OO
	adjMatrix = vector<vector<int>>(n, vector<int>(n, OO));

	for (int i = 0; i < m; ++i)
	{
		int from, to, weight;
		cin >> from >> to >> weight; // 0-based
		if (from == to)
			continue;
		// undirected
		adjMatrix[from][to] = min(adjMatrix[from][to], weight);
		adjMatrix[to][from] = adjMatrix[from][to];
	}
}

int main()
{
	// freopen("data.txt", "rt", stdin);

	vector<vector<int>> adjMatrix;
	read_graph(adjMatrix);

	int mstCost = MST(adjMatrix, 0);

	cout << mstCost << "\n"; // 14

	return 0;
}

/*
6 7
0 5 6
0 1 2
1 2 4
2 3 4
2 5 3
3 4 1
5 4 4

 */
