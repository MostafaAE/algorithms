// https://leetcode.com/problems/min-cost-to-connect-all-points/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <limits>
#include <queue>
using namespace std;

const int OO = 2 * 1e6 * 1000; // careful from OO value

struct edge
{
	int to, w;

	edge(int to, int w) : to(to), w(w)
	{
	}

	bool operator<(const edge &e) const
	{
		return w > e.w;
	}
};

// O(E logV)
int MST(const vector<vector<edge>> &adjList, int n, int src = 0)
{
	// We MUST use vis array. We can't use dist array.
	// dist was valid for shortest path problem, as we can't
	// come with shorter distance. In case MST, it is possible
	// to reach a discovered node with shorter edge later
	// In lecture example, consider node(2)
	// discovered early from node(1) with cost 4
	// but later can be reached from node(5) with cost 3
	vector<int> dist(n, OO);
	vector<bool> vis(n, 0);
	dist[src] = 0;
	int mstCost = 0;

	priority_queue<edge> q; // small to large
	q.push(edge(src, 0));

	while (!q.empty())
	{
		// Get node with the minimum distance
		edge mnEdge = q.top();
		int mnIdx = mnEdge.to;
		q.pop();

		if (vis[mnIdx]) // visited
			continue;

		mstCost += mnEdge.w;

		for (const auto &edge : adjList[mnIdx])
		{ // relax
			int to = edge.to, weight = edge.w;

			if (dist[to] > weight)
			{
				dist[to] = weight;
				q.push({to, dist[to]});
			}
		}
		vis[mnIdx] = true;
	}
	return mstCost;
}

int read_graph(vector<vector<edge>> &adjList)
{
	int n, m; // nodes and edges;
	cin >> n >> m;

	adjList = vector<vector<edge>>(n);

	for (int i = 0; i < m; ++i)
	{
		int from, to, weight;
		cin >> from >> to >> weight;
		adjList[from].push_back({to, weight});
		adjList[to].push_back({from, weight});
	}
	return n;
}

int main()
{
	// freopen("data.txt", "rt", stdin);

	vector<vector<edge>> adjList;
	int n = read_graph(adjList);

	int mstCost = MST(adjList, n);

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
