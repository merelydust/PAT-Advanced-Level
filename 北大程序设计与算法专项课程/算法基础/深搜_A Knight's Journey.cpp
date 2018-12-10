//STATUS:C++_AC_16MS_168K
#include<stdio.h>
#include<memory.h>
const int MAXN=10;
int DFS(int tot,int rear,int x,int y);
int p,q,way[MAXN*MAXN][2]={0},vis[MAXN][MAXN];
int dx[8]={-2,-2,-1,-1,1,1,2,2},   //按字典序方向行走
dy[8]={-1,1,-2,2,-2,2,-1,1};
int main()
{
    //    freopen("in.txt","r",stdin);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        memset(vis,0,sizeof(vis));   //预处理
        vis[0][0]=1;       //标记A1已经经过
        scanf("%d%d",&p,&q);
        printf("Scenario #%d:\n",i);
        if(DFS(p*q,1,0,0)){
            for(int j=0,tot=p*q;j<tot;j++)
                printf("%c%d",way[j][0]+'A',way[j][1]+1);
            putchar('\n');
        }
        else printf("impossible\n");
        if(i!=n)putchar('\n');
    }
    return 0;
}

int DFS(int tot,int rear,int x,int y)
{
    if(rear==tot)return 1;   //搜索成功
    
    else for(int i=0;i<8;i++){
        int nx=x+dx[i],ny=y+dy[i];
        if(nx>=0&&nx<q && ny>=0&&ny<p && !vis[nx][ny]){
            vis[nx][ny]=1;      //标记为经过
            if(DFS(tot,rear+1,nx,ny)){     //搜索下一个
                way[rear][0]=nx,way[rear][1]=ny;
                return 1;
            }
            vis[nx][ny]=0;   //搜索不成功，标记为未经过
        }
    }
    return 0;   //搜索不成功
}
