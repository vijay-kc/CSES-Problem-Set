#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> dist(n + 1, -1), par(n + 1, -1);
    dist[1] = 1;
    queue<int> q;
    q.push(1);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto v : adj[u])
        {
            if (dist[v] == -1)
            {
                dist[v] = dist[u] + 1;
                par[v] = u;
                q.push(v);
            }
        }
    }

    if (dist[n] == -1)
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    cout << dist[n] << "\n";
    vector<int> path;
    int cur = n;
    while (cur != -1)
    {
        path.push_back(cur);
        cur = par[cur];
    }
    reverse(path.begin(), path.end());
    for (int x : path)
        cout << x << " ";
    cout << "\n";
    return 0;
}