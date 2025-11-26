#include <bits/stdc++.h>
using namespace std;
class DSU
{
public:
    vector<int> par, rank;
    DSU(int n)
    {
        rank.resize(n + 1, 0);
        par.resize(n + 1);
        for (int i = 1; i < n + 1; i++)
        {
            par[i] = i;
        }
    }
    int findPar(int x)
    {
        if (x == par[x])
        {
            return x;
        }
        return par[x] = findPar(par[x]);
    }
    void unionByRank(int x, int y)
    {
        int px = findPar(x);
        int py = findPar(y);
        if (px < py)
        {
            par[px] = py;
        }
        else if (px > py)
        {
            par[py] = px;
        }
        else
        {
            par[py] = px;
            rank[px]++;
        }
    }
};
int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> roads(m);
    int s, e;
    for (int i = 0; i < m; i++)
    {
        cin >> s >> e;
        roads[i] = {s, e};
    }
    DSU ds(n);
    for (auto r : roads)
    {
        ds.unionByRank(r.first, r.second);
    }
    unordered_map<int, vector<int>> comp;
    for (int i = 1; i <= n; i++)
    {
        int p = ds.findPar(i);
        comp[p].push_back(i);
    }
    if (comp.size() == 1)
    {
        cout << 0;
        return 0;
    }
    vector<pair<int, int>> req_road;
    vector<int> ultPar;
    for (auto &c : comp)
    {
        ultPar.push_back(c.second[0]);
    }
    for (int i = 1; i < ultPar.size(); i++)
    {
        req_road.push_back({ultPar[0], ultPar[i]});
    }
    cout << req_road.size() << endl;
    for (auto &rr : req_road)
    {
        cout << rr.first << " " << rr.second << endl;
    }

    return 0;
}