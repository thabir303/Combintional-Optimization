#include <bits/stdc++.h>
using namespace std;

#define MAXN 100
#define INF INT_MAX

int d[MAXN][MAXN];

void reset(int c)
{
    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < c; j++)
        {
            d[i][j] = INF;
        }
    }
}

int floyd(int n)
{
    for(int k=0; k<n; k++)
     for(int i=0; i<n; i++)
      for(int j=0; j<n; j++)
         d[i][j] = min(d[i][j], max(d[i][k], d[k][j]));

}
int main()
{
    int n, e, u, v, w, q, cnt=1;
    while(cin >> n >> e >> q)
    {
        if(n==0 and e==0 and q==0) break;

        reset(n);
        for(int i=0; i<e; i++)
        {
            cin >> u >> v >> w;
            u--;
            v--;
            d[u][v] = d[v][u] = w;
        }
        floyd(n);
        int a, b;
        if(cnt != 1) cout << endl;
        cout << "Case #" << cnt++ << "\n";
        for(int i=0; i<q; i++)
        {
            cin >> a >> b;
            a--;
            b--;
            if(d[a][b] == INF)
                cout << "no path\n";
            else
                cout << d[a][b] << "\n";
        }
    }
}
/*
7 9 3
1 2 50
1 3 60
2 4 120
2 5 90
3 6 50
4 6 80
4 7 70
5 7 40
6 7 140
1 7
2 6
6 2
7 6 3
1 2 50
1 3 60
2 4 120
3 6 50
4 6 80
5 7 40
7 5
1 7
2 4
0 0 0
*/
