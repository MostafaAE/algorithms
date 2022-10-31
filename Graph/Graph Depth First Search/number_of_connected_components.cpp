#include <bits/stdc++.h>
using namespace std;

/*
 * If we started from a node, performed dfs(node), we can mark all reachable nodes
 * Now, all these nodes are a connected component
 *
 * If there is a node NOT marked, then not reachable. Hence ANOTHER component
 * Again do DFS from it and so on
 *
 * Overall: minor code changes to the dfs code
 *
 * The time & memory complexity is the same O(E+V)
 * As in each call, we cover a sub-graph
 *
 * In graph theory, this problem can be done in other several ways
 * 		Graph BFS
 * 		Graph Union-Find (Disjoint set)
 */

typedef vector<vector<int>> GRAPH;

void add_directed_edge(GRAPH &graph, int from, int to)
{
    graph[from].push_back(to);
}

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

void dfs(GRAPH &graph, int node, vector<bool> &visited)
{
    visited[node] = true;
    for (int neighbour : graph[node])
        if (!visited[neighbour])
            dfs(graph, neighbour, visited);
}

int count_components(int n, vector<vector<int>> &edges)
{
    int count{};
    GRAPH graph(n);
    vector<bool> visited(n);

    // building the graph
    for (vector<int> p : edges)
        add_undirected_edge(graph, p[0], p[1]);

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            count++;
            dfs(graph, i, visited);
        }
    }
    return count;
}

int main()
{
    int n = 5;
    vector<vector<int>> edges{{0, 1}, {1, 2}, {2, 3}, {3, 4}}; // must see it, otherwise RTE
    cout << count_components(n, edges) << endl;
    cout << "\n\nNO RTE\n";
    return 0;
}