#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> GRAPH;

void add_directed_edge(GRAPH &graph, int from, int to)
{
    graph[from].push_back(to);
}

// O( E+V )
vector<int> topsort(const GRAPH &adjList)
{
    int sz = adjList.size();
    vector<int> indegree(sz, 0);

    // compute indegrees of nodes
    for (int i = 0; i < sz; ++i)
        for (int j : adjList[i])
            indegree[j]++;

    queue<int> ready;
    // add all current nodes that has indegree(0)
    for (int i = 0; i < sz; ++i)
        if (!indegree[i])
            ready.push(i);

    vector<int> ordering;
    while (!ready.empty())
    {
        // keep picking a ready node
        int i = ready.front();
        ready.pop();
        ordering.push_back(i);

        for (int j : adjList[i])
            // remove its outgoing edges
            if (--indegree[j] == 0)
                // If a neighbor is ready, add it
                ready.push(j);
    }

    // There are cycles
    if (ordering.size() != adjList.size())
        ordering.clear();

    return ordering;
}

int main()
{
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
            add_directed_edge(graph, from, to);
        }

        vector<int> ordering = topsort(graph);

        if (ordering.empty())
            cout << "There is a cycle\n";
        else
        {
            for (int node : ordering)
                cout << node << " ";
            cout << "\n";
        }
    }
    // must see it, otherwise RTE
    cout << "\n\nNO RTE\n";
    return 0;
}

/*
 2
 10 10
 5 0
 5 7
 6 7
 6 8
 0 1
 7 2
 8 2
 1 2
 2 4
 2 3

 9 11
 5 0
 5 7
 6 7
 6 8
 0 1
 7 2
 8 2
 1 2
 2 4
 2 3
 2 6


 Output
 5 6 9 0 7 8 1 2 4 3
 There is a cycle


 */