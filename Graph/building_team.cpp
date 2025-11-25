#include <bits/stdc++.h>
using namespace std;
// void bfs(int s,vector<vector<int>>&adj,vector<int>&team){
//     team[s]=1;
//     queue<int> q;
//     q.push(s);
//     while (!q.empty())
//     {
//         int u = q.front();
//         q.pop();
//         for (auto v : adj[u])
//         {
//             if (team[v] == -1)
//             {   if(team[u]==1){
//                     team[v] = 2;
//                 }else{
//                     team[v]=1;
//                 }
//                 q.push(v);
//             }else if(team[v]==team[u]){
//                 cout<<"IMPOSSIBLE"<<endl;
//                 exit(0);
//             }
//         }
//     }
// }
void dfs(int s,vector<vector<int>>&adj,vector<int>&team){
    team[s]=1;
    stack<int> q;
    q.push(s);
    while (!q.empty())
    {
        int u = q.top();
        q.pop();
        for (auto v : adj[u])
        {
            if (team[v] == -1)
            {   if(team[u]==1){
                    team[v] = 2;
                }else{
                    team[v]=1;
                }
                q.push(v);
            }else if(team[v]==team[u]){
                cout<<"IMPOSSIBLE"<<endl;
                exit(0);
            }
        }
    }
}
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
    vector<int> team(n+1,-1);

    

    for (int i=1;i<=n;i++){
        if(team[i]==-1)dfs(i,adj,team);
    }
    for (int i=1;i<=n;i++){
        cout << team[i] << " ";
    }
    
    return 0;
}