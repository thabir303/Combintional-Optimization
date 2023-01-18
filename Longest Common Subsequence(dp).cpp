#include<bits/stdc++.h>
using namespace std;

#define up 'u'
#define left 'l'
#define diagon 'd'

const int MAX=10005;
int c[MAX][MAX];
char b[MAX][MAX];

void lcsLength(char x[], char y[], int m, int n){
    //The length of the LCS if one of the sequences
    //is empty is zero
    for(int i=0;i<=m;i++){
        c[i][0]=0;
    }

    for(int i=0;i<=n;i++){
        c[0][i]=0;
    }

    // calculation part
    for(int mi=1;mi<=m;mi++){
        for(int ni=1;ni<=n;ni++){
            // case if x[mi]=y[ni]
            if(x[mi-1] == y[ni-1]){
                c[mi][ni]=c[mi-1][ni-1]+1;
                b[mi][ni]=diagon;
            }else if(c[mi-1][ni] >= c[mi][ni-1]){
                c[mi][ni]=c[mi-1][ni];
                b[mi][ni]=up;
            }else{
                c[mi][ni]=c[mi][ni-1];
                b[mi][ni]=left;
            }
        }
    }
}

void printLCS(char x[], int mi, int ni){
    if(mi == 0 || ni == 0){
        return;
    }

    if(b[mi][ni] == diagon){
        //printf("%c",x[mi]);
        printLCS(x, mi-1, ni-1);
        printf("%c",x[mi-1]);
    }else if(b[mi][ni] == up){
        printLCS(x, mi-1, ni);
    }else{
        printLCS(x, mi, ni-1);
    }
}

int main()
{
    //freopen("lcs.txt", "r", stdin);
    char x[MAX], y[MAX];
    int m,n;
    scanf("%s %s", x, y);
    scanf("%d %d",&m,&n);

    lcsLength(x,y,m,n);

    //cout << x << " " << y << "\n";

    printf("Longest common subsequence length: %d\n", c[m][n]);
    printf("The subsequence is: ");
    printLCS(x, m, n);
    printf("\n");
}

