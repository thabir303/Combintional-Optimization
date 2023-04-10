#include <bits/stdc++.h>

using namespace std;

int cutRodUtil(vector<int>& price, int ind, int N, vector<vector<int>>& dp)
{

    if(ind == 0)
    {
        return N*price[0];
    }

    if(dp[ind][N]!=-1)
        return dp[ind][N];

    int notTaken = 0 + cutRodUtil(price,ind-1,N,dp);

    int taken = INT_MIN;
    int rodLength = ind+1;
    if(rodLength <= N)
        taken = price[ind] + cutRodUtil(price,ind,N-rodLength,dp);

    return dp[ind][N] = max(notTaken,taken);
}


int cutRod(vector<int>& price,int N)
{

    vector<vector<int>> dp(N,vector<int>(N+1,-1));
    return cutRodUtil(price,N-1,N,dp);
}

int main()
{

    vector<int> price = {2,5,7,8,10};

    int n = price.size();

    cout<<"The Maximum price generated is "<<cutRod(price,n);
}
/*
Time Complexity: O(N*N)
Reason: There are N*(N+1) states therefore at max ‘N*(N+1)’ new problems will be solved.
Space Complexity: O(N*N) + O(N)
Reason: We are using a recursion stack space(O(N)) and a 2D array ( O(N*(N+1)).
*/
