#include <bits/stdc++.h>
using namespace std;

void dijkstra(int n, int s, vector<vector<pair<int, long long>>> &g, vector<long long> &dist)
{
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
    dist[s] = 0;
    pq.push({0, s});
    while (!pq.empty())
    {
        auto it = pq.top();
        int d=it.first;
        int u=it.second;
        pq.pop();
        if (d != dist[u]) continue;
        for (auto g : g[u])
        {   int v=g.first;
            int w=g.second;
            if (dist[v] > d + w)
            {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    int a, b, c;
    vector<vector<long long>> edge(m, vector<long long>(3));
    vector<vector<pair<int, long long>>> g(n + 1), gR(n + 1);

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        edge[i]={a, b, c};
        g[a].push_back({b, c});
        gR[b].push_back({a, c});
    }
    vector<long long> dist(n + 1, 1e18), distR(n + 1, 1e18);

    dijkstra(n, 1, g, dist);
    dijkstra(n, n, gR, distR);

    long long ans = dist[n];

    for (auto e : edge)
    {
        int u = e[0], v = e[1], w = e[2];
        if (dist[u] == 1e18 || distR[v] == 1e18)
            continue;
        long long p = dist[u] + (w / 2) + distR[v];
        ans = min(ans, p);
    }
    cout << ans;
    return 0;
}