#include <bits/stdc++.h>
using namespace std;

// void dfs(int i,int j,vector<vector<char>>&mp,vector<vector<int>>&vis){
//     int n=mp.size(),m=mp[0].size();
//     vis[i][j]=1;
//     stack<pair<int,int>>st;
//     st.push({i,j});
//     vector<pair<int,int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
//     while(!st.empty()){
//         int x=st.top().first;
//         int y=st.top().second;
//         st.pop();
//         for(int a=0;a<4;a++){
//             int nx=x+dir[a].first;
//             int ny=y+dir[a].second;
//             if( nx>=0 && nx<n && ny>=0 && ny<m && mp[nx][ny]=='.' && !vis[nx][ny]){
//                 vis[nx][ny]=1;
//                 st.push({nx,ny});
//             }
//         }
//     }
// }
void bfs(int i,int j,vector<vector<char>>&mp,vector<vector<int>>&vis){
    int n=mp.size(),m=mp[0].size();
    vis[i][j]=1;
    queue<pair<int,int>>q;
    q.push({i,j});
    vector<pair<int,int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int a=0;a<4;a++){
            int nx=x+dir[a].first;
            int ny=y+dir[a].second;
            if( nx>=0 && nx<n && ny>=0 && ny<m && mp[nx][ny]=='.' && !vis[nx][ny]){
                vis[nx][ny]=1;
                q.push({nx,ny});
            }
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> mp(n, vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mp[i][j];
        }
    }
    int ans=0;
    vector<vector<int>> vis(n, vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mp[i][j]=='.' && vis[i][j]!=1){
                // dfs(i,j,mp,vis);
                bfs(i,j,mp,vis);
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}