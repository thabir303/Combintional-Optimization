#include<bits/stdc++.h>
using namespace std;
#define N 101
#define INF 999999


int graph[N][N];

int main()
{
    int cases = 0;
    int u, v;


    while(cin >> u >> v and ( u || v )  )
    {

        set<int> st;

        for(int i = 0; i < N; ++i)
        {
            for(int j = 0; j < N; ++j)
            {
                graph[i][j] = INF;
            }
        }

        for(int i = 0; i < N; ++i)
        {
            graph[i][i] = 0;
        }

        graph[u-1][v-1] = 1;
        st.insert(u);
        st.insert(v);

        while( cin >> u >> v and  ( u || v ) )
        {

            graph[u-1][v-1] = 1;

            st.insert(u);
            st.insert(v);
        }

        for(int k = 0; k < N; ++k)
        {
            for(int i = 0; i < N; ++i)
            {
                for(int j = 0; j < N; ++j)
                {

                    if( graph[i][j] > graph[i][k] + graph[k][j] )
                    {
                        graph[i][j] = graph[i][k] + graph[k][j];
                    }
                }
            }
        }

        int sum = 0;
        for(int i = 0; i < N; ++i)
        {
            for(int j = 0; j < N; ++j)
            {
                if(i != j && graph[i][j] != INF)
                {
                    sum = sum + graph[i][j];
                }
            }
        }

    int setSize = st.size();
    cout<<"Case "<< ++cases<< ": average length between pages = "<< fixed << setprecision(3) << (float) sum / (setSize * (setSize-1));
    cout << " clicks" << endl;

    }
}
/*
1 2 2 4 1 3 3 1 4 3 0 0
1 2 1 4 4 2 2 7 7 1 0 0
0 0
*/
