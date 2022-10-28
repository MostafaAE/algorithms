#include <bits/stdc++.h>
using namespace std;
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

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;

    GRAPH graph(nodes);

    for (int e = 0; e < edges; e++)
    {
        int from, to;
        cin >> from >> to;
        add_directed_edge(graph, from, to);
    }

    print_adjacency_list(graph);
    // must see it, otherwise RTE
    cout << "\n\nNO RTE\n";
    return 0;
}

/*

5 5
0 1
1 2
2 3
4 3
3 2


Output
Node 0 has neighbours: 1
Node 1 has neighbours: 2
Node 2 has neighbours: 3
Node 3 has neighbours: 2
Node 4 has neighbours: 3

 */
