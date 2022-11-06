#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> GRAPH;

void add_directed_edge(GRAPH &graph, int from, int to)
{
	graph[from].push_back(to);
}

void dfs(GRAPH &graph, int node, vector<int> &started, vector<int> &finished, int &time)
{
	started[node] = time++;

	for (int neighbour : graph[node])
	{
		if (started[neighbour] == -1)
		{ // tree edge
			cout << "Tree Edge: " << node << " " << neighbour << "\n";
			dfs(graph, neighbour, started, finished, time);
		}
		else
		{ // 3 cases for a visited node
			if (started[node] < started[neighbour])
				cout << "Forward Edge: " << node << " " << neighbour << "\n";
			else if (finished[neighbour] == -1)
				cout << "Back Edge (cycle): " << node << " " << neighbour << "\n";
			else
				cout << "Cross Edge: " << node << " " << neighbour << "\n";
		}
	}
	finished[node] = time++;
}

void classify_edges(GRAPH &graph)
{
	int nodes = graph.size();

	vector<int> started(nodes, -1), finished(nodes, -1);
	int time = 1;

	for (int i = 0; i < nodes; ++i)
		if (started[i] == -1) // not visited
			dfs(graph, i, started, finished, time);

	cout << "*****************************\n";
}

int main()
{
	// freopen("edge_classification-input", "rt", stdin);

	int cases, nodes, edges;
	cin >> cases;
	while (cases--)
	{
		cin >> nodes >> edges;

		GRAPH graph(nodes); // observe: empty lists

		for (int e = 0; e < edges; ++e)
		{
			int from, to;
			cin >> from >> to;
			add_directed_edge(graph, from, to);
		}
		classify_edges(graph);
	}

	return 0;
}

/*
Input:
5
3 3
0 1
0 2
2 1

3 3
0 1
0 2
1 2

9 9
1 2
2 3
3 4
1 5
5 6
6 7
6 8
6 3
4 2

7 11
0 1
0 6
1 2
1 6
2 3
2 0
3 1
3 6
4 2
4 3
4 5

9 9
0 1
0 2
1 3
1 4
2 5
2 6
4 7
8 2
8 6




Output:
Tree Edge: 0 1
Tree Edge: 0 2
Cross Edge: 2 1
*****************************
Tree Edge: 0 1
Tree Edge: 1 2
Forward Edge: 0 2
*****************************
Tree Edge: 1 2
Tree Edge: 2 3
Tree Edge: 3 4
Back Edge (cycle): 4 2
Tree Edge: 1 5
Tree Edge: 5 6
Tree Edge: 6 7
Tree Edge: 6 8
Cross Edge: 6 3
*****************************
Tree Edge: 0 1
Tree Edge: 1 2
Tree Edge: 2 3
Back Edge (cycle): 3 1
Tree Edge: 3 6
Back Edge (cycle): 2 0
Forward Edge: 1 6
Forward Edge: 0 6
Cross Edge: 4 2
Cross Edge: 4 3
Tree Edge: 4 5
*****************************
Tree Edge: 0 1
Tree Edge: 1 3
Tree Edge: 1 4
Tree Edge: 4 7
Tree Edge: 0 2
Tree Edge: 2 5
Tree Edge: 2 6
Cross Edge: 8 2
Cross Edge: 8 6
*****************************

 */
