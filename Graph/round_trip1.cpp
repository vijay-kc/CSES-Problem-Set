#include <bits/stdc++.h>
using namespace std;
vector<int> path;
bool dfs(int u, int p, vector<vector<int>> &adj, vector<int> &vis, vector<int> &par)
{
    vis[u] = 1;
    for (auto v : adj[u])
    {
        if (v == p)
            continue;
        if (vis[v])
        {
            path.push_back(v);
            int c = u;
            while (c != v)
            {
                path.push_back(c);
                c = par[c];
            }
            path.push_back(v);
            reverse(path.begin(), path.end());
            if (path.size() > 3)
                return true;
        }
        else
        {
            par[v] = u;
            if (dfs(v, u, adj, vis, par))
                return true;
        }
    }
    return false;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bool found = false;
    vector<int> vis(n + 1, 0), par(n + 1, -1);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if (dfs(i, -1, adj, vis, par))
            {
                found = true;
                break;
            }
        }
    }

    if (found)
    {
        cout << path.size() << endl;
        for (auto it : path)
        {
            cout << it << " ";
        }
    }
    else
    {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}