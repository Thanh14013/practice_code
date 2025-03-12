#include <bits/stdc++.h>
using namespace std;

class Graph
{

    int V;
    vector<vector<int>> adj;

    Graph(int V)
    {
        this->V = V;
        adj = vector<vector<int>>(V);
    };

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void printGraph()
    {
        for (int i = 0; i < V; i++)
        {
            cout << "Adjacency list of vertex " << i << "\n head ";
            for (auto x : adj[i])
                cout << "-> " << x;
            printf("\n");
        }
    }

    void DFS(int v)
    {
        vector<bool> visited(V, false);
        function<void(int)> dfs = [&](int v)
        {
            visited[v] = true;
            cout << v << " ";
            for (auto x : adj[v])
            {
                if (!visited[x])
                    dfs(x);
            }
        };
        dfs(v);
    }

    void BFS(int v)
    {
        vector<bool> visited(V, false);
        queue<int> q;
        q.push(v);
        visited[v] = true;
        int d = 1;
        while (!q.empty())
        {
            int size = q.size();
            cout << "level " << d++ << ": ";
            for (int i = 0; i < size; i++)
            {
                int u = q.front();
                q.pop();
                cout << u << " ";
                for (auto x : adj[u])
                {
                    if (!visited[x])
                    {
                        visited[x] = true;
                        q.push(x);
                    }
                }
            }
        }
    }

    bool isCycle()
    {
        vector<bool> visited(V, false);
        function<bool(int, int)> dfs = [&](int v, int parent)
        {
            visited[v] = true;
            for (auto x : adj[v])
            {
                if (!visited[x])
                {
                    if (dfs(x, v))
                        return true;
                }
                else if (x != parent)
                    return true;
            }
            return false;
        };
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                if (dfs(i, -1))
                    return true;
            }
        }
        return false;
    }
};