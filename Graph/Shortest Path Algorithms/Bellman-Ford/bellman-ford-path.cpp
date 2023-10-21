#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <limits>
#include <random>
using namespace std;

/*

One simple idea, use prev[] to maintain the node directly before me
	Initialize with -1 to indicate nothing before it
	Recall we extend with an edge[a-b], then prev[b] = a

So a path like: 0 1 4 2 3
	prev[3] = 2
	prev[2] = 4
	prev[4] = 1
	prev[1] = 0
	prev[0] = -1

Starting from 3, we get the list: 3 2 4 1 0, then reverse it

*/

const int OO = (int)1e6;

struct edge
{
	int from, to, w;

	edge(int from, int to, int w) : from(from), to(to), w(w)
	{
	}
};

vector<int> BellmanFord(vector<edge> &edgeList, int n, int src, vector<int> &prev)
{
	vector<int> dist(n, OO);
	dist[src] = 0;

	prev = vector<int>(n, -1);

	for (int it = 0; it < n - 1; ++it)
	{
		bool any_updates = false;
		// 2 inner loops just iterate on edges relax all to nodes
		for (int j = 0; j < (int)edgeList.size(); ++j)
		{
			edge &ne = edgeList[j]; // enhance its ne.to

			if (dist[ne.to] > dist[ne.from] + ne.w)
			{
				dist[ne.to] = dist[ne.from] + ne.w;
				prev[ne.to] = ne.from;
				any_updates = true;
			}
		}
		if (!any_updates)
		{
			// cout << "stop after " << it + 1 << " iterations\n";
			break; // if a complete iteration does nothing, then more iterations doesn't help
		}
	}
	return dist;
}

vector<int> buildPath(const vector<int> &prev, int target)
{
	// start from last node and move toward the source
	vector<int> path;
	for (int i = target; i > -1 && path.size() <= prev.size(); i = prev[i])
		path.push_back(i);
	// now path is reversed [target to src]. reverse it
	reverse(path.begin(), path.end());
	return path;
}

int main()
{
	vector<edge> edgeList{{0, 1, 1}, {1, 2, 99}, {2, 3, 5}, {1, 4, 1}, {4, 2, 3}, {4, 5, 6}, {5, 3, 7}};
	vector<int> prev;

	vector<int> sp = BellmanFord(edgeList, 6, 0, prev);

	for (int i = 0; i < (int)sp.size(); ++i)
		cout << i << " " << sp[i] << "\n";

	int target = 3;
	vector<int> path = buildPath(prev, target);
	for (int node : path)
		cout << node << " ";
	cout << endl;
	/*
	0 0
	1 1
	2 5
	3 10
	4 2
	5 8

	0 1 4 2 3 		path from 0 to 3

	 */

	return 0;
}
