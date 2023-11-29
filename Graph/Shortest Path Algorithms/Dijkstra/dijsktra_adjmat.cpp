#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <limits>
#include <random>
using namespace std;

const int OO = (int)1e6;

vector<int> Dijkstra(const vector<vector<int>> &adjMax, int src)
{ // O(n^2)
	int n = adjMax.size();
	vector<bool> vis(n, 0);
	vector<int> dist(n, OO);
	dist[src] = 0;

	while (true)
	{
		// Find the minimum nodes of non-deleted nodes
		int val = OO, idx = -1;
		for (int i = 0; i < n; ++i)
			if (!vis[i] && dist[i] < val)
				val = dist[i], idx = i;
		// Nothing more (e.g. after N-1 iterations / disconnected G)
		if (idx == -1)
			break;
		// Relax with the selected node
		for (int i = 0; i < n; ++i)
			if (dist[i] > (val = dist[idx] + adjMax[idx][i]))
				dist[i] = val;

		vis[idx] = true; // delete
	}
	return dist;
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
			continue; // let's ignore even if -ve
		adjMatrix[from][to] = min(adjMatrix[from][to], weight);
	}
}

int main()
{
	// freopen("data.txt", "rt", stdin);

	vector<vector<int>> adjMatrix;
	read_graph(adjMatrix);

	vector<int> sp = Dijkstra(adjMatrix, 0);

	for (int i = 0; i < (int)sp.size(); ++i)
		cout << i << " " << sp[i] << "\n";

	/*
		0 0
		1 9
		2 4
		3 6
		4 7

	 */

	return 0;
}

/*
5 7
0 2 4
0 3 10
2 3 2
2 4 3
3 4 2
4 1 2
1 2 2

 */
