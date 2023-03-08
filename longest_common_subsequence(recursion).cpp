#include<bits/stdc++.h>
using namespace std;
string s,t;

int lcs(int i,int j)
{

  if(i==0 || j==0)
    return 0;

   if (s[i-1] == t[j-1])
        return 1 + lcs(i-1, j-1);
    else
        return max(lcs( i, j-1), lcs( i-1, j));

}

int main(){

   cin>>s>>t;

   cout<<lcs(s.size(),t.size());

}
/*
AGGTAB
GXTXAYB
*/
