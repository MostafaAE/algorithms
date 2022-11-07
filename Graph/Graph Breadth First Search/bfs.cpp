#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> GRAPH;
const int OO{1000000}; // A big value expressing infinity

void add_directed_edge(GRAPH &graph, int from, int to)
{
    graph[from].push_back(to);
}

void add_undirected_edge(GRAPH &graph, int from, int to)
{
    graph[from].push_back(to);
    graph[to].push_back(from);
}

void print_adjaceny_list(GRAPH &graph)
{
    int nodes = graph.size();
    for (int from = 0; from < nodes; ++from)
    {
        cout << "Node " << from << " has neighbors: ";
        for (int to = 0; to < (int)graph[from].size(); ++to)
            cout << graph[from][to] << " ";
        cout << "\n";
    }
}

vector<int> bfs_v1(GRAPH &graph, int start)
{
    vector<int> len((int)graph.size(), OO);
    queue<pair<int, int>> q;

    q.push({start, 0});
    len[start] = 0;

    while (!q.empty())
    {
        auto [cur, level] = q.front();
        q.pop();

        for (int neighbour : graph[cur])
        {
            // not visited yet
            if (len[neighbour] == OO)
            {
                q.push({neighbour, level + 1});
                len[neighbour] = level + 1;
            }
        }
    }
    return len;
}

vector<int> bfs_v2(GRAPH &graph, int start)
{
    vector<int> len((int)graph.size(), OO);
    queue<int> q;

    q.push(start);
    len[start] = 0;
    int level = 0;

    while (!q.empty())
    {
        int sz = q.size();

        while (sz--)
        {
            int cur = q.front();
            q.pop();

            for (int neighbour : graph[cur])
            {
                // not visited yet
                if (len[neighbour] == OO)
                {
                    q.push(neighbour);
                    len[neighbour] = level + 1;
                }
            }
        }
        level++;
    }
    return len;
}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;

    GRAPH graph(nodes); // observe: empty lists

    for (int e = 0; e < edges; ++e)
    {
        int from, to;
        cin >> from >> to;
        add_undirected_edge(graph, from, to);
    }

    vector<int> bfs_traversal = bfs_v2(graph, 1);

    for (int node : bfs_traversal)
        cout << node << " ";
    cout << "\n";

    return 0;
}

/*
 9 11
 1 3
 1 5
 1 6
 3 4
 3 5
 3 7
 5 4
 6 0
 4 2
 0 2
 2 8

Output
2 0 3 1 2 1 1 2 4

 */
