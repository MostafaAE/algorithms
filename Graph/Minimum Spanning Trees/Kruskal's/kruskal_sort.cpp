#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <limits>
#include <queue>
using namespace std;

class UnionFind
{
private:
	vector<int> rank, parent;
	int forests;

	void link(int x, int y)
	{
		if (rank[x] > rank[y])
			swap(x, y); // force x to be smaller

		parent[x] = y;
		if (rank[x] == rank[y]) // equal case
			rank[y]++;
	}

public:
	UnionFind(int n)
	{
		rank = vector<int>(n), parent = vector<int>(n);
		forests = n; // Number of the current forests

		for (int i = 0; i < n; ++i)
			parent[i] = i, rank[i] = 1;
	}

	int find_set(int x)
	{
		if (x == parent[x])
			return x;
		// This is the path compression
		// the top parent is returned and we re-link
		return parent[x] = find_set(parent[x]);
	}

	bool union_sets(int x, int y)
	{
		x = find_set(x), y = find_set(y);
		if (x != y)
		{ // Different components
			link(x, y);
			forests--; // 2 merged into 1
		}
		return x != y;
	}
};

struct edge
{
	int from, to, w;

	edge(int from, int to, int w) : from(from), to(to), w(w)
	{
	}

	bool operator<(const edge &e) const
	{
		return w < e.w;
	}
};

int MST_Kruskal(vector<edge> &edgeList, int n)
{ // O(E logV)
	UnionFind uf(n);
	vector<edge> edges; // Save MST edges
	int mstCost = 0;

	sort(edgeList.begin(), edgeList.end());

	for (auto &e : edgeList)
	{
		if (uf.union_sets(e.from, e.to))
		{
			// If added, then part of tree
			mstCost += e.w;
			edges.push_back(e);
		}
	}
	// if size of edges != n-1, then no full MST
	return mstCost;
}

int read_graph(vector<edge> &edgeList)
{
	int n, m; // nodes and edges;
	cin >> n >> m;

	for (int i = 0; i < m; ++i)
	{
		int from, to, weight;
		cin >> from >> to >> weight;
		// One direction is enough for Kruskal
		edgeList.push_back({from, to, weight});
	}
	return n;
}

int main()
{
	// freopen("data.txt", "rt", stdin);

	vector<edge> edgeList;
	int n = read_graph(edgeList);

	int mstCost = MST_Kruskal(edgeList, n);

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