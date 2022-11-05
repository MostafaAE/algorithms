#include <bits/stdc++.h>
using namespace std;

/*
 * Recall:
 * 		A tree is an undirected graph of N nodes and N-1 edges
 * 			Single path from any node to another
 * 			No cycles
 * 			If you added a single edge ==> created a single cycle
 *
 * 		A forest: collection of subtrees. So total #edges <= N-1
 *
 *
 * In fact, the code is almost direct DFS. We already discussed before finding cycle in the matrix
 * 		The whole trick is to add the parent node to dfs parameters we came from to avoid going
 * 		If we visited a visited node, there must be a cycle
 *
 * But is not dfs O(E+V)?
 * For an undirected graph to have no cycles, it must be a forest of at most n-1 edges
 *
 * So now we have 2 cases:
 * 1) Graph is a forest of at most n-1 edges and no cycles
 * 		Clearly: E = O(V). So we are O(V)
 *
 * 2) A general graph of cycles
 * 		Then in the worst case after N edges we must go back to a visited node!
 * 		Imagine simple graph of 5 nodes
 * 		0 -> 1 -> 2 -> 3 -> 4 -> 0
 *
 * So in both cases the algorithm is O(V)
 */

typedef vector<vector<int>> GRAPH;

void add_undirected_edge(GRAPH &graph, int from, int to)
{
    graph[from].push_back(to);
    graph[to].push_back(from);
}

void print_adjacency_list(const GRAPH &graph)
{
    int nodes = (int)graph.size();
    for (int from = 0; from < nodes; from++)
    {
        cout << "Node " << from << " has neighbours: ";
        for (int to = 0; to < (int)graph[from].size(); to++)
            cout << graph[from][to] << "";
        cout << "\n";
    }
}

bool dfs(GRAPH &graph, int node, vector<bool> &visited, int parent = -1)
{
    visited[node] = true;

    for (int neighbour : graph[node])
    {
        // Avoid fake undirected edge cycle
        if (neighbour == parent)
            continue;

        // Cycle
        if (visited[neighbour])
            return true;

        else if (dfs(graph, neighbour, visited, node))
            return true;
    }
    return false;
}

bool has_cycle_undirected(GRAPH &graph_adj_list)
{
    int n = (int)graph_adj_list.size();

    vector<bool> visited(n, 0);

    // handle separate Connected Componentss
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && dfs(graph_adj_list, i, visited))
            return true;
    }
    return false;

    // Tip: if we know number of edges, then if edges >= n, it must contain cycles
}

int main()
{
    // freopen("detect_cycle-input.txt", "rt", stdin);
    int cases;
    cin >> cases;

    while (cases--)
    {
        int nodes, edges;
        cin >> nodes >> edges;

        GRAPH graph(nodes);

        for (int e = 0; e < edges; ++e)
        {
            int from, to;
            cin >> from >> to;
            add_undirected_edge(graph, from, to);
        }
        if (has_cycle_undirected(graph))
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
}

/*

Input:
7

4 3
0 1
1 2
2 3

6 5
0 1
0 2
1 3
1 4
2 5

6 6
0 1
0 2
1 3
1 4
2 5
1 5

6 3
0 1
1 2
2 0


6 3
0 1
2 3
4 5

6 0

6 4
0 1
2 3
3 4
4 2


Output:
No
No
Yes
Yes
No
No
Yes

 */
