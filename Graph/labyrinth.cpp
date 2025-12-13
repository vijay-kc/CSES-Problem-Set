#include <bits/stdc++.h>
using namespace std;


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
    vector<vector<int>> vis(n, vector<int>(m,0));
    vector<vector<pair<int,int>>> par(n, vector<pair<int,int>>(m,{-1,-1}));
    vector<vector<char>> path(n, vector<char>(m));
    int sx,sy,ex,ey;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mp[i][j]=='A'){
               sx=i;
               sy=j;
            }
            if(mp[i][j]=='B'){
                ex=i;
                ey=j;
            }
        }
    }

    vis[sx][sy]=1;
    queue<pair<int,int>>q;
    q.push({sx,sy});
    vector<pair<int,int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
    vector<char> turn = {'D','U','R','L'};
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        if(x==ex&&y==ey)break;
        for(int a=0;a<4;a++){
            int nx=x+dir[a].first;
            int ny=y+dir[a].second;
            if( nx>=0 && nx<n && ny>=0 && ny<m && mp[nx][ny]!='#' && !vis[nx][ny]){
                vis[nx][ny]=1;
                par[nx][ny]={x,y};
                path[nx][ny]=turn[a];
                q.push({nx,ny});
            }
        }
    }

    if(!vis[ex][ey]){
        cout<<"NO";
        return 0;
    }
    cout<<"YES"<<endl;
    string root="";
    int x = ex, y = ey;
    while(x!=sx || y!=sy){
        root+=path[x][y];
        auto p=par[x][y];
        x=p.first;
        y=p.second;
    }
    cout<<root.size()<<endl;
    reverse(root.begin(),root.end());
    cout<<root<<endl;
    
    return 0;
}