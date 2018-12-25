#include<cstdio>
#include<climits>
#include<iostream>
using namespace std;
int t,n,x,ans;
inline int calc(int a,int b,int c){
    return a*b*2+a*c*2+b*c*2;
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        x = n; ans = INT_MAX;
        for(int i = 1;i <= n; ++i){
            if(x%i == 0){
                x/=i;
                for(int j=1; j <= x; j++){
                    if(x%j == 0){
                        x/=j;
                        ans = min(ans, calc(i,j,x));
                        x *= j;
                    }
                }
                x*=i;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
