#include<bits/stdc++.h>
using namespace std;

int memCutRod(int p[], int n, int dp[])
{
    // memorization part
    if(dp[n] != -1)
    {
        return dp[n];
    }

    // handle base case
    if(n == 0)
    {
        return dp[n]=0;
    }

    // calculation part
    int ans=-100000;
    for(int i=1; i<=n; i++)
    {
        ans=max(ans, p[i]+memCutRod(p, n-i, dp));
    }

    return dp[n]=ans;
}

int calc(int n, int p[])
{
    int dp[n+1];

    for(int i=0; i<=n; i++)
    {
        dp[i]=-1;
    }

    int res= memCutRod(p, n, dp);

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
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&p[i]);
    }

    printf("Maximum revenue of cutting rod: %d\n",calc(n,p));
}

