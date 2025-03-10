#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    vector<vector<pair<int, int>>> adj;

    Graph(int V)
    {
        this->V = V;
        adj.resize(V);
    };

    void addEdge(int u, int v, int w)
    {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    void dijkstra(int v)
    {
        vector<int> dist(V, INT_MAX);
        dist[v] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, v});
        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();
            for (auto x : adj[u])
            {
                int v = x.first;
                int w = x.second;
                if (dist[v] > dist[u] + w)
                {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        for (int i = 0; i < V; i++)
        {
            cout << "Distance from " << v << " to " << i << " is " << dist[i] << "\n";
        }
    }
};