#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int num[7],tmp[7],len,mm,t,f;//num-分割方式 tmp-临时分割 len-分割组数 mm-最大分割和 f-判多解(rejected)

int getlen(int x)//求x位数对应的10^n 用以dfs时取余(分割)
{
    int cnt = 1;
    while(x)
    {
        x /= 10;
        cnt *= 10;
    }
    return cnt/10;
}

void dfs(int rest,int sum,int site,int l,int p)//p 0无前导零 1有前导
{
    if(sum + rest <=  t  && sum + rest >= mm)
    {
        if(sum + rest == mm || p == 1)//满足条件时多解或某组有前导零
        {
            f = 1;
            mm = sum + rest;
            return;
        }
        f = 0;
        mm = sum + rest;
        memcpy(num,tmp,sizeof(tmp));
        num[site++] = rest;
        len = site;
        return;
    }
    
    if(sum + rest < t && sum + rest < mm) return;//当前已小 后继更小
    for(int i = l; i >= 1; i /= 10)
    {
        tmp[site] = rest/i;
        if(i > 10 && rest%i/(i/10) == 0)  dfs(rest%i, sum + rest/i, site+1, i/100,1);//判分割后余下的数是否有前导零
        else dfs(rest%i, sum + rest/i, site+1, i/10,p);
    }
    
}

int main()
{
    int n;
    while(~scanf("%d %d",&t,&n) && (t+n))
    {
        f = 0;
        len = 0;
        mm = -1;
        dfs(n,0,0,getlen(n),0);
        
        if(mm == -1) puts("error");
        else if(f) puts("rejected");
        else
        {
            printf("%d",mm);
            for(int i = 0; i < len; ++i) printf(" %d",num[i]);
            puts("");
        }
    }
    return 0;
}
