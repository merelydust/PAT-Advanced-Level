#include<cstdio>
#include<iostream>
using namespace std;
#define N 55
int f[N][N],n,ans;
int main(){
    while(scanf("%d",&n)!=EOF){
        f[0][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){
                f[i][j]=f[i-1][j-1]+f[i-j][j];
            }
        }
        ans=0;
        for(int i=1;i<=n;i++) ans+=f[n][i];
        printf("%d\n",ans);
    }
    return 0;
}
