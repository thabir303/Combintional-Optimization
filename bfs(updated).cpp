/// maximum connected component count

#include<bits/stdc++.h>
using namespace std;

vector<int>adj[100000];
int  lev[100000];
int cnt;

void bfs(int s)
{
    memset(lev, -1 ,sizeof(lev));

    lev[s]=0;
    queue<int>q;
    q.push(s);

    while(!q.empty())
    {
        int u=q.front();
        q.pop();

         for(auto v : adj[u])
         {
             if(lev[v] != 0)
             {
                 lev[v] = lev[u] + 1;
                 q.push(v);
             }
    }

    }
}

int main()
{
    int T; cin>>T;
    while(T--)
    {
        for(int i = 0; i<100000;i++) adj[i].clear();
        int n,m;
        cin>>n>>m;
        for(int i =0; i<m;i++)
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        bfs(1);
        cout<<lev[n]<<endl;
    }
}
/*
8 5
1 2
2 3
2 4
5 7
6 8
*/


