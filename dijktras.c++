#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <set>
using namespace std;

typedef pair<int, int> pii;

void dijkstra(int V, vector<vector<pii>> &adj, int source)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> dist(V, INT_MAX);
    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty())
    {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u])
            continue;

        for (auto &edge : adj[u])
        {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    for (int i = 0; i < V; i++)
    {
        if (dist[i] == INT_MAX)
            cout << "INF ";
        else
            cout << dist[i] << " ";
    }
    cout << endl;
}

int main()
{
    int V = 5;
    vector<vector<pii>> adj(V);

    set<pair<int, pii>> unique_edges;

    unique_edges.insert({0, {1, 10}});
    unique_edges.insert({0, {2, 5}});
    unique_edges.insert({1, {2, 2}});
    unique_edges.insert({1, {3, 1}});
    unique_edges.insert({2, {1, 3}});
    unique_edges.insert({2, {3, 9}});
    unique_edges.insert({2, {4, 2}});
    unique_edges.insert({3, {4, 4}});
    unique_edges.insert({4, {0, 7}});

    for (const auto &edge : unique_edges)
    {
        adj[edge.first].push_back(edge.second);
    }

    int source = 0;
    cout << "Shortest distances from source node " << source << ": ";
    dijkstra(V, adj, source);

    return 0;
}
