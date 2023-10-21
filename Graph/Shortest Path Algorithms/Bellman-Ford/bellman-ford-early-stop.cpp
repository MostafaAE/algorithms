#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <limits>
#include <random>
using namespace std;

const int OO = (int)1e6;

struct edge
{
	int from, to, w;

	edge(int from, int to, int w) : from(from), to(to), w(w)
	{
	}
};

vector<int> BellmanFord(vector<edge> &edgeList, int n, int src)
{

	vector<int> dist(n, OO);
	dist[src] = 0;

	for (int it = 0; it < n - 1; ++it)
	{
		bool anyUpdates = false;

		// 2 inner loops just iterate on edges relax all to nodes
		for (int j = 0; j < (int)edgeList.size(); ++j)
		{
			edge &ne = edgeList[j]; // enhance its ne.to

			if (dist[ne.to] > dist[ne.from] + ne.w)
			{
				dist[ne.to] = dist[ne.from] + ne.w;
				anyUpdates = true;
			}
		}

		cout << "\nDistances after iteration " << it + 1 << "\n";
		for (int i = 0; i < (int)dist.size(); ++i)
			cout << i << " " << dist[i] << "\n";
		// Check if there is a difference between this iteration and the previous

		if (!anyUpdates)
		{
			cout << "\nStop after " << it + 1 << " iterations\n";
			break;
		}
	}
	return dist;
}

int main()
{
	int n = 6;
	vector<edge> edgeList{{0, 1, 1}, {1, 2, 99}, {2, 3, 5}, {1, 4, 1}, {4, 2, 3}, {4, 5, 6}, {5, 3, 7}};
	// vector<edge> edgeList{{0, 1, 1}, {1, 2, 1}, {2, 3, 1}, {3, 4, 1}, {4, 5, 1}};
	// vector<edge> edgeList{{4, 5, 1}, {3, 4, 1}, {2, 3, 1}, {1, 2, 1}, {0, 1, 1}};

	vector<int> sp = BellmanFord(edgeList, n, 0);

	cout << "\nFinal Result: " << endl;
	for (int i = 0; i < (int)sp.size(); ++i)
		cout << i << " " << sp[i] << "\n";

	/*
	 0 0
	 1 1
	 2 5
	 3 10
	 4 2
	 5 8
	 */

	return 0;
}
