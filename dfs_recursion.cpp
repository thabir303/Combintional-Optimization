#include<bits/stdc++.h>
using namespace std;
const int N =1e5+10;
vector<int>g[N];

bool vis[N];
int dis[N];
queue<int>Q;
void dfs(int node){

    vis[node] = 1;
    cout<<node << " ";
    for(int adj: g[node]){
        if(vis[adj]) continue;
        dfs(adj);
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v); // directed graph
        //g[y].push_back(x);
    }
    cout<<"order\t" ;
    //int source; cin>>source;
    dfs(0);
    cout<<endl;

}
/*
9 9
0 2
0 3
0 1
1 7
7 8
2 4
3 4
4 5
5 6
*/

