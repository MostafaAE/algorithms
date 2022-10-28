#include <bits/stdc++.h>
using namespace std;
struct edge
{
    int to;
    int cost;
};

typedef vector<vector<edge>> GRAPH;

void add_directed_edge(GRAPH &graph, int from, int to, int cost)
{
    graph[from].push_back({to, cost});
}

void add_undirected_edge(GRAPH &graph, int from, int to, int cost)
{
    graph[from].push_back({to, cost});
    graph[to].push_back({from, cost});
}

void print_adjacency_list(const GRAPH &graph)
{
    int nodes = (int)graph.size();
    for (int from = 0; from < nodes; from++)
    {
        cout << "Node " << from << " has neighbours: ";
        for (int to = 0; to < (int)graph[from].size(); to++)
            cout << "(to: " << graph[from][to].to << ", cost: " << graph[from][to].cost << ") ";
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
        int from, to, cost;
        cin >> from >> to >> cost;
        add_directed_edge(graph, from, to, cost);
    }

    print_adjacency_list(graph);
    // must see it, otherwise RTE
    cout << "\n\nNO RTE\n";
    return 0;
}

/*

6 7
2 1 10
2 5 20
2 0 77
2 3 33
0 5 45
1 4 60
5 4 10


Output
Node 0 has neighbours: (to: 5, cost: 45)
Node 1 has neighbours: (to: 4, cost: 60)
Node 2 has neighbours: (to: 1, cost: 10) (to: 5, cost: 20) (to: 0, cost: 77) (to: 3, cost: 33)
Node 3 has neighbours:
Node 4 has neighbours:
Node 5 has neighbours: (to: 4, cost: 10)

 */