#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> GRAPH;
void add_directed_edge(GRAPH &graph, int from, int to)
{
    graph[from][to] += 1;
}

void add_undirected_edge(GRAPH &graph, int from, int to)
{
    graph[from][to] += 1;
    graph[to][from] += 1;
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
                     << " there are " << graph[from][to] << " edges" << endl;
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
        int from, to;
        cin >> from >> to;
        add_directed_edge(graph, from, to);
    }

    print_adjacency_matrix(graph);
    // must see it, otherwise RTE
    cout << "\n\nNO RTE\n";
    return 0;
}

/*

5 8
0 1
1 2
2 3
4 3
3 2
4 3
0 1
4 3

Output
From 0 to 1 there are 2 edges
From 1 to 2 there are 1 edges
From 2 to 3 there are 1 edges
From 3 to 2 there are 1 edges
From 4 to 3 there are 3 edges

 */