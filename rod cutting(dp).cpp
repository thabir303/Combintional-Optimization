#include<bits/stdc++.h>
using namespace std;

const int inf_=-1e9;

int memCutRod(int p[], int n, int r[]){
    // memorization part
    if(r[n] != inf_){
        return r[n];
    }

    // handle base case
    if(n == 0){
        return r[n]=0;
    }

    // calculation part
    int q=inf_;
    for(int i=1;i<=n;i++){
        q=max(q, p[i]+memCutRod(p, n-i, r));
    }

    return r[n]=q;
}

int calc(int n, int p[]){
    int r[n+1];

    for(int i=0;i<=n;i++){
        r[i]=inf_;
    }

    int res= memCutRod(p, n, r);

    // for(int i=0;i<=n;i++){
    //     cout << r[i] << "\n";
    // }

    return res;
}

int main()
{


    int n;
    scanf("%d",&n);

    int p[n+1];
    for(int i=1;i<=n;i++){
        scanf("%d",&p[i]);
    }

    printf("Maximum revenue of cutting rod: %d\n",calc(n,p));
}

