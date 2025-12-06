#include <bits/stdc++.h>
using namespace std;

int main()
{

    long long n, m;
    cin >> n >> m;
    vector<vector<pair<int, long long>>> adj(n + 1);

    for (long long i = 0; i < m; i++)
    {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    vector<long long> dist(n + 1, 1e18);
    dist[1] = 0;

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, 1});

    while (!pq.empty())
    {
        auto it = pq.top();
        int d = it.first;
        int u = it.second;
        pq.pop();
        if (d != dist[u])
            continue;

        for (auto i : adj[u])
        {
            int v = i.first;
            int w = i.second;
            if (dist[v] > d + w)
            {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }

    for (long long i = 1; i <= n; i++)
    {
        cout << dist[i] << " ";
    }
    cout << "\n";

    return 0;
}
