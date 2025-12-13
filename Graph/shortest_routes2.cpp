#include <bits/stdc++.h>
using namespace std;
//Floyd-Warshall algorithm
int main() {
    long long n, m, q;
    cin >> n >> m >> q;

    vector<vector<long long>> dist(n + 1, vector<long long>(n + 1, 1e18));

    for (long long i = 1; i <= n; i++) {
        dist[i][i] = 0;
    }

    for (long long i = 0; i < m; i++) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], w);
        dist[v][u] = min(dist[v][u], w);
    }

    for (long long k = 1; k <= n; k++) {
        for (long long i = 1; i <= n; i++) {
            for (long long j = 1; j <= n; j++) {
                if (dist[i][k] != 1e18 && dist[k][j] != 1e18) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        if (dist[a][b] == 1e18) {
            cout << -1 << endl;
        } else {
            cout << dist[a][b] << endl;
        }
    }

    return 0;
}



// #include <bits/stdc++.h>
// using namespace std;

// void dijkstra(int start, const vector<vector<pair<int, long long>>> &adj, vector<long long> &dist) {
//     fill(dist.begin(), dist.end(), 1e18);  
//     dist[start] = 0;

//     priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
//     pq.push({0, start});

//     while (!pq.empty()) {
//         auto [d, u] = pq.top();
//         pq.pop();

//         if (d != dist[u]) continue;  

//         for (auto &[v, w] : adj[u]) {
//             if (dist[v] > d + w) {
//                 dist[v] = d + w;
//                 pq.push({dist[v], v});
//             }
//         }
//     }
// }

// int main() {
//     long long n, m, q;
//     cin >> n >> m >> q;

//     vector<vector<pair<int, long long>>> adj(n + 1);  

//     for (long long i = 0; i < m; i++) {
//         int u, v;
//         long long w;
//         cin >> u >> v >> w;
//         adj[u].push_back({v, w});
//         adj[v].push_back({u, w});  
//     }

//     vector<vector<long long>> dist(n + 1,vector<long long> (n+1,1e18));  
//     for(int i=1;i<=n;i++){
//         dijkstra(i, adj, dist[i]);  

//     }
//     for (int i = 0; i < q; i++) {
//         int a, b;
//         cin >> a >> b;


//         if (dist[a][b] == 1e18) {
//             cout << -1 << endl;  
//         } else {
//             cout << dist[a][b] << endl; 
//         }
//     }

//     return 0;
// }



