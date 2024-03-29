///   ***   ---   |||		 In the name of ALLAH		|||   ---   ***   ///

#include<bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef double dl;

#define endl '\n'
#define PB push_back
#define F first
#define S second
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define sz(x) (int)x.size()

const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const ll infLL = 9000000000000000000;
#define MOD 1000000007

#define mem(a,b) memset(a, b, sizeof(a) )
#define sqr(a) ((a) * (a))

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);


const int mx = 1e5+123;
vii adj[mx];
ll dist[mx];

void dijkstra ( int s, int n )
{
    for ( int i = 0; i <= n; i++ ) dist[i] = infLL; /// initilization
    dist[s] = 0; /// initilizing source distance
    priority_queue < pll, vll, greater<pll> > pq;
    pq.push ( { 0, s } ); /// pushing source in queue

    while ( !pq.empty() ) {
        int u = pq.top().S;
        ll curD = pq.top().F;
        pq.pop();

        if ( dist[u] < curD ) continue; // important

        for ( auto p : adj[u] ) {
            int v = p.F;
            ll w = p.S;
            if ( curD + w < dist[v] ) { // relax operation
                dist[v] = curD + w;
                pq.push ( { dist[v], v } );
            }
        }
    }

}

int main()
{
	optimize();

    int n, m;
    cin >> n >> m;
    for ( int i = 1; i <= m; i++ ) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].PB ( { v, w } );
        adj[v].PB ( { u, w } );
    }

    dijkstra ( 1, n );

    for ( int i = 1; i <= n; i++ ) cout << dist[i] << " ";
    cout << endl;

	return 0;
}

/*

5 7
1 3 3
1 2 2
1 4 6
2 0 6
2 3 7
0 4 3
3 4 5

*/
