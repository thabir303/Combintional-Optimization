#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int>g[N];
bool vis[N];

void dfs(int vertex)
{
    /* Take action on vertex after entering the vertex */
    //if(vis[vertex]) return; //this can be written if inside for we haven't written vis child condn
    cout<<vertex<<endl;
    vis[vertex]=true;
    for(int child: g[vertex])
    {
        cout<<"parent"<<vertex<<",child"<<child<<endl;
        if(vis[child]) continue;
        /* Take action on child before entering the child node */
        dfs(child);
        /* Take action on child after existing the child node */
    }
    /* Take action on child before existing the vertex */
}

int main()
{
    int vertex,edge;
    cin>>vertex>>edge;
    for(int i=0; i<edge; i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    dfs(1);
}
/*
6 9
1 3
1 5
3 5
3 4
3 6
3 2
2 6
4 6
5 6
*/
