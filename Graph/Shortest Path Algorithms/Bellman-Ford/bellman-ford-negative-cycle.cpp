// https://leetcode.com/problems/network-delay-time/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <limits>
#include <random>
using namespace std;

/*

How can we know there is a negative cycle?

Based on a simple observation.
Assume there is no negative cycle
then we know every path must have maximum N-1 edges
So we relax N-1 full iterations

What if one extra iteration also relaxed?
	Then we have a shorter path of N edges
	This means there is a negative cycle


So just iterate one more iteration. If anything relaxed, we have -ve cycle
*/

const int OO = (int)1e6;

struct edge
{
	int from, to, w;

	edge(int from, int to, int w) : from(from), to(to), w(w)
	{
	}
};

bool BellmanFord(vector<edge> &edgeList, int n, int src, vector<int> &dist, vector<int> &prev)
{
	prev = vector<int>(n, -1);
	dist = vector<int>(n, OO);
	dist[src] = 0;

	for (int it = 0; it < n; ++it)
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
		if (it == n - 1)
			return true; // cycle
	}
	return false;
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
	// vector<edge> edgeList { { 0, 1, 1 }, { 1, 2, 99 }, { 2, 3, 5 }, { 1, 4, 1 }, { 4, 2, 3 }, { 4, 5, 6 }, { 5, 3, 7 } };
	vector<edge> edgeList{{0, 1, 1}, {1, 2, 99}, {2, 3, 5}, {1, 4, 1}, {4, 2, 3}, {4, 5, 6}, {5, 3, 7}, {3, 1, -1000}};
	vector<int> prev, sp;

	bool negative_cycle = BellmanFord(edgeList, 6, 0, sp, prev);

	if (negative_cycle)
	{
		cout << "There is a negative cycle";
		return 0;
	}

	for (int i = 0; i < (int)sp.size(); ++i)
		cout << i << " " << sp[i] << "\n";

	int target = 3;
	vector<int> path = buildPath(prev, target);
	for (int node : path)
		cout << node << " ";

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
