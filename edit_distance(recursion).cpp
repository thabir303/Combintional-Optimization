#include <bits/stdc++.h>
using namespace std;
string s1,s2;
/*
int min(int x, int y, int z)
 {
     return min(min(x, y), z);
  }
*/
int editDist( int m, int n)
{

    if (m == 0)
        return n;
    if (n == 0)
        return m;

    if (s1[m - 1] == s2[n - 1])
        return editDist( m - 1, n - 1);

    // If last characters are not same, consider all three
    // operations on last character of first string,
    // recursively compute minimum cost for all three
    // operations and take minimum of three values.
    return 1+ min({editDist(m, n - 1), editDist( m - 1, n), editDist(m - 1,n - 1)});
}

int main()
{

    cin>>s1>>s2;
    cout << editDist(s1.size(),s2.size());

    return 0;
}

