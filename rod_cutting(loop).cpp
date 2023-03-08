#include <bits/stdc++.h>
using namespace std;
int main()
{
    int i, j, l, n;
    cout<<"Number of piece: \n";
    cin>>n;
    int piece[n], profit[n];

    printf("Enter pieces\n");

    for (i = 0; i < n; i++)
        scanf("%d", &piece[i]);

    printf("Enter the profits\n");

    for (i = 0; i < n; i++)
        scanf("%d", &profit[i]);

    printf("Enter the length of the rod\n");
    scanf("%d", &l);

    int memo[n + 1][l + 1];
    for (i = 0; i <= n; i++)
        memo[i][0] = 0;
    for (j = 0; j <= l; j++)
        memo[0][j] = 0;

    int len[l];
    for (i = 0; i < l; i++)
        len[i] = i + 1;

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= l; j++)
        {
            if (piece[i - 1] > len[j - 1])
                memo[i][j] = memo[i - 1][j];
            else
            {
                /* if (memo[i - 1][j] > profit[i - 1] + memo[i][len[j - 1] - piece[i - 1]])
                     memo[i][j] = memo[i - 1][j];
                 else
                 {
                     memo[i][j] = profit[i - 1] + memo[i][len[j - 1] - piece[i - 1]];
                 } */
                memo[i][j] =max(memo[i - 1][j], profit[i - 1] + memo[i][len[j - 1] - piece[i - 1]]);
            }
        }
    }

    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= l; j++)
        {
            printf("%d ", memo[i][j]);
        }
        printf("\n");
    }

    printf("length of the rod\n");
    i = n;
    j = l;

    while (memo[i][j] != 0)
    {
        if (memo[i][j] != memo[i - 1][j])
        {
            printf("%d\n", piece[i - 1]);
            j = len[j - 1] - piece[i - 1];
        }
        else
            i--;
    }
}
/*
4
1 2 3 4
2 5 9 6
5
*/

