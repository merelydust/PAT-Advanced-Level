#include <cstdio>
using namespace std;
const int Max = 1000001;
int a[Max];
int main(){
    int n, m;
    scanf("%d", &n);
    for(int k = 0; k < n; ++k)
        scanf("%d", &a[k]);
    scanf("%d", &m);
    a[n] = (1<<31) -1;
    int mid = (n+m -1)/2;
    int cnt = 0, i = 0, j= 0, b = 0;
    if(m > 0){scanf("%d", &b);}
    while(cnt < mid){
        if(j >= m) b = (1<<31) -1;
        if(a[i] < b)i++;
        else {scanf("%d", &b);j++;}
        cnt++;
    }
    printf("%d\n", ((a[i]<b)? a[i]:b));
    return 0;
}
