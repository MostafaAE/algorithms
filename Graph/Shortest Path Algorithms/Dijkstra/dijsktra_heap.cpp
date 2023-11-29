// https://leetcode.com/problems/network-delay-time/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <limits>
#include <queue>
using namespace std;

const int OO = (int)1e6;

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

void print_queue(priority_queue<edge> &q)
{
	priority_queue<edge> q2;

	while (!q.empty())
	{
		edge mnEdge = q.top();
		q.pop();
		cout << "To=" << mnEdge.to << " - W=" << mnEdge.w << "\n";

		q2.push(mnEdge);
	}
	q = q2;
	cout << "******************\n";
}

// O(E logV)
vector<int> Dijkstra(const vector<vector<edge>> &adjList, int n, int src)
{
	vector<int> dist(n, OO);
	vector<bool> vis(n, 0);
	dist[src] = 0;

	priority_queue<edge> q; // small to large
	q.push(edge(src, 0));

	while (!q.empty())
	{
		print_queue(q);
		for (int i = 0; i < (int)dist.size(); ++i)
		{
			cout << i << " " << dist[i] << "\n";
		}
		cout << "+++++++++++++++\n";

		// Get node with the minimum distance
		edge mnEdge = q.top();
		int mnIdx = mnEdge.to;
		q.pop();

		// The same node might come several times
		if (vis[mnIdx])
		{
			cout << "Already visited\n";
			continue;
		}

		// Relax with the outgoing edges of the min node
		for (const auto &edge : adjList[mnIdx])
		{
			int to = edge.to, weight = edge.w;

			if (dist[to] > dist[mnIdx] + weight)
			{
				dist[to] = dist[mnIdx] + weight;
				// Add new edges
				q.push({to, dist[to]});
				cout << "Relax " << to << " " << dist[to] << "\n";
			}
		}
		vis[mnIdx] = true;
	}

	return dist;
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
	}
	return n;
}

int main()
{
	// freopen("data.txt", "rt", stdin);

	vector<vector<edge>> adjList;
	int n = read_graph(adjList);

	vector<int> sp = Dijkstra(adjList, n, 0);

	for (int i = 0; i < (int)sp.size(); ++i)
		cout << i << " " << sp[i] << "\n";

	return 0;
}

/*
7 12
0 1 2
0 3 1
1 4 10
1 3 3
2 0 4
2 5 5
3 4 2
3 6 4
3 2 2
3 5 8
4 6 6
6 5 1

5 7
0 2 4
0 3 10
2 3 2
2 4 3
3 4 2
4 1 2
1 2 2

 */
