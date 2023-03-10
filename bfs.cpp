#include<bits/stdc++.h>
using namespace std;
const int N =1e5+10;
vector<int>g[N];

bool vis[N];
int dis[N];
queue<int>Q;

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
    //cout<<"Source node :" ;
    //int source; cin>>source;
    Q.push(0);
    vis[0]=1;
    dis[0]=0;

    vector<int>order;
    while(!Q.empty())
    {
        int node=Q.front();
        Q.pop();
        order.push_back(node);

        for(int adj : g[node])
        {
            if(vis[adj]) continue;
            vis[adj] = 1;
            dis[adj] =dis[node] + 1;
            Q.push(adj);

        }
    }
    cout<<"order :\t" ;
    for(int v : order) cout<< v <<" ";
    cout<<endl;

    for(int node=0; node<=n; node++)

        cout<<"node : "<<node<<"\t"<<"distance : "<<dis[node]<<endl;

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
