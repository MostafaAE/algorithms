#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> GRAPH;
void add_directed_edge(GRAPH &graph, int from, int to, int cost)
{
    graph[from][to] = cost;
}

void add_undirected_edge(GRAPH &graph, int from, int to, int cost)
{
    graph[from][to] = cost;
    graph[to][from] = cost;
}

void print_adjacency_matrix(const GRAPH &graph)
{
    int nodes = (int)graph.size();
    for (int from = 0; from < nodes; from++)
    {
        for (int to = 0; to < nodes; to++)
        {
            if (graph[from][to])
                cout << "From " << from << " To " << to
                     << " the cost is " << graph[from][to] << endl;
        }
    }
}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;

    GRAPH graph(nodes, vector<int>(nodes));

    for (int e = 0; e < edges; e++)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        add_undirected_edge(graph, from, to, cost);
    }

    print_adjacency_matrix(graph);
    // must see it, otherwise RTE
    cout << "\n\nNO RTE\n";
    return 0;
}

/*

5 6
0 1 10
1 2 7
2 3 9
3 4 50
0 4 52
2 4 36

Output
From 0 to 1 the cost is 10
From 0 to 4 the cost is 52
From 1 to 0 the cost is 10
From 1 to 2 the cost is 7
From 2 to 1 the cost is 7
From 2 to 3 the cost is 9
From 2 to 4 the cost is 36
From 3 to 2 the cost is 9
From 3 to 4 the cost is 50
From 4 to 0 the cost is 52
From 4 to 2 the cost is 36
From 4 to 3 the cost is 50

 */