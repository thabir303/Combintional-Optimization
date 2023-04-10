/// maximum connected component count

#include<bits/stdc++.h>
using namespace std;

vector<int>adj[1000];
bool vis[1000];
int cnt;

void dfs(int u)
{
    vis[u]=1;


    for(auto v : adj[u])
    {
        if(vis[v] != true  )
        {
            dfs(v);
        }
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    //int ans = 0;
    for(int i =1; i <= n;i++)
    {
        if(vis[i] != true )
        {
            dfs(i);
            cnt++;
        }
    }
    cout<<cnt<<endl;
}
/*
8 5
1 2
2 3
2 4
5 7
6 8
*/

