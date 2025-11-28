#include <bits/stdc++.h>
using namespace std;
int INF = 1e9;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> mp(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mp[i][j];
        }
    }
    vector<vector<int>> monster(n, vector<int>(m, INF));
    vector<vector<int>> player(n, vector<int>(m, INF));
    int sx, sy;
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mp[i][j] == 'M')
            {
                q.push({i, j});
                monster[i][j] = 0;
            }
            if (mp[i][j] == 'A')
            {
                sx = i;
                sy = j;
            }
        }
    }

    vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<char> turn = {'D', 'U', 'R', 'L'};
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int a = 0; a < 4; a++)
        {
            int nx = x + dir[a].first;
            int ny = y + dir[a].second;
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && monster[nx][ny] > monster[x][y] + 1 && mp[nx][ny] != '#')
            {
                monster[nx][ny] = monster[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    vector<vector<pair<int, int>>> par(n, vector<pair<int, int>>(m, {-1, -1}));
    vector<vector<char>> path(n, vector<char>(m));

    queue<pair<int, int>> qp;
    qp.push({sx, sy});
    player[sx][sy] = 0;

    while (!qp.empty())
    {
        int x = qp.front().first;
        int y = qp.front().second;
        qp.pop();
        if (x == 0 || x == n - 1 || y == 0 || y == m - 1)
        {
            cout << "YES" << endl;
            string root = "";
            while (x != sx || y != sy)
            {
                root += path[x][y];
                auto p = par[x][y];
                x = p.first;
                y = p.second;
            }
            cout << root.size() << endl;
            reverse(root.begin(), root.end());
            cout << root << endl;
            return 0;
        }

        for (int a = 0; a < 4; a++)
        {
            int nx = x + dir[a].first;
            int ny = y + dir[a].second;
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && mp[nx][ny] != '#' && player[nx][ny] == INF)
            {
                
               int arrival_time = player[x][y] + 1;
                if (arrival_time < monster[nx][ny]) {
                    player[nx][ny] = arrival_time;
                    par[nx][ny] = {x, y};
                    path[nx][ny] = turn[a];
                    qp.push({nx, ny});
                }
            }
        }
    }

    cout << "NO"<<endl;
   

    return 0;
}