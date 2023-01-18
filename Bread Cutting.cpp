#include<bits/stdc++.h>
using namespace std;

const int Max=1005;
int dp[Max][Max];
int arr[Max];
int n,l;

int calc(int first, int last){

    if(dp[first][last] != -1) return dp[first][last];


    bool found=false;
    for(int i=1;i<=n;i++){
        if(arr[i]>first and arr[i]<last){
            found=true;
            break;
        }
    }

    if(!found){
        return dp[first][last]=0;
    }


    int ans=INT_MAX;

    for(int i=1;i<=n;i++){
        if(arr[i]>first and arr[i]<last){
            ans=min(ans, last-first+calc(first,arr[i])+calc(arr[i],last));
        }
    }


    return dp[first][last]=ans;
}

int main()
{
    scanf("%d %d",&l,&n);

    for(int i=1;i<=n;i++){
        scanf("%d",&arr[i]);
    }

    for(int i=0;i<=l;i++){
        for(int ii=0;ii<=l;ii++){
            dp[i][ii]=-1;
        }
    }

    printf("Minimum cost of cutting bread: %d\n",calc(0,l));
}

