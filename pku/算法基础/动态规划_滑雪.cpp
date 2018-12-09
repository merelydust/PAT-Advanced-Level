#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=100+5;
int a[maxn][maxn];
int dp[maxn][maxn];
int n,m;
int dir[4][2]={1,0,0,1,-1,0,0,-1};
int DP(int x,int y)
{
    
    if(dp[x][y])
        return dp[x][y];
    int ans=0;
    for(int i=0;i<4;i++)
    {
        int xx=x+dir[i][0];
        int yy=y+dir[i][1];
        if(xx<0||xx>=n||yy<0||yy>=m)
            continue;
        if(a[xx][yy]<a[x][y])
            ans=max(ans,DP(xx,yy));
    }
    dp[x][y]=ans+1;
    return dp[x][y];
}
int main()
{
    while(cin>>n>>m)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                cin>>a[i][j];
        }
        memset(dp,0,sizeof(dp));
        int maxx=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                maxx=max(maxx,DP(i,j));
            }
        }
        cout<<maxx<<endl;
    }
    return 0;
}

