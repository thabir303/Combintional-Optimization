#include<bits/stdc++.h>
using namespace std;
int c[100][100];
char p[100][100];
vector<int>v;
string s1,s2;
int ED(string s1,string s2){

      for(int i=0;i<=s1.size();i++)
      {
          for(int j=0;j<=s2.size();j++)
          {
              if(i==0 && j==0)
              c[i][j]=0;
              else if(i==0)
              {
                  c[i][j]=c[i][j-1]+1;
              }
              else if(j==0) c[i][j]=c[i-1][j]+1;
              else
                {
                    if(s1[i-1]==s2[j-1])
                        {
                            c[i][j]=c[i-1][j-1];
                            p[i][j]='r';
                        }
                   else
                    {
                        c[i][j]=1+min({c[i][j-1],c[i-1][j],c[i-1][j-1]});
                        if(c[i][j]==c[i][j-1]+1)
                        {
                            p[i][j]='e';
                        }
                        else if(c[i][j]==c[i-1][j]+1)
                        {
                             p[i][j]='i';
                        }
                        else if(c[i][j]==c[i-1][j-1]+1)
                        {
                             p[i][j]='r';
                        }

                    }

              }
          }
      }

}
void path(int a,int b)
{
     if(a==0 || b==0) return ;
    if(p[a][b]=='r')
        {
         path(a-1,b-1);
          printf("%d",c[a-1][b-1]);

        }
    else if(p[a][b]=='i')
       {
           path(a-1,b);
           //v.push_back(c[s1.size()-1][s1.size()]);

       }
       else if(p[a][b]=='e')
       {
           path(a,b-1);
           //v.push_back(c[s1.size()][s1.size()-1]);

       }

    }


int main()
{
     cin>>s1>>s2;
    ED(s1,s2);
    int a=s1.size(),b=s2.size();
    cout<<c[s1.size()][s2.size()]<<endl;
    path(a,b);
    cout<<endl;
    for(int i=0;i<=s1.size();i++)
      {
          for(int j=0;j<=s2.size();j++)
          {
              cout<<c[i][j]<<" ";
          }
          cout<<endl;
      }

}
/*
adceg
abcfg
*/

