#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int c,n,k,v[9];
char map[9][9];
bool a[9],b[9];
int dfs(int x)
{
    for(int i=v[x-1];i<=n;i++)
        for(int j=1;j<=n;j++)
            if(!a[i]&&!b[j]&&map[i][j]=='#')
            {
                v[x]=i;
                a[i]=1;
                b[j]=1;
                if(x==k) c++;
                else dfs(x+1);
                a[i]=0;
                b[j]=0;
            }
    return 0;
}
int main()
{
    while(cin>>n>>k&&n!=-1&&k!=-1)
    {
        c=0;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                cin>>map[i][j];
        dfs(1);
        cout<<c<<endl;
    }
}
