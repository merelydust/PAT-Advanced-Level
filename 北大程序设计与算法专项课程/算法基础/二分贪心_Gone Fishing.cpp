/***
 h小时 n个湖
 从湖1开始 任意湖结束
 湖之间的移动时间=5*ti分钟
 每个湖起始5分钟期望抓到的鱼数量fi 每过去五分钟期望抓鱼会下降di
 期望抓鱼数<=di的时间段 不会抓到鱼
 最大化抓到的鱼
 
 输出 多个测试用例
 n
 h
 a line of n integers specifying fi (1 <= i <=n)
 a line of n integers di (1 <=i <=n)
 a line of n - 1 integers ti
 遇到n=0终止测试
 
 
 输出在每个湖停留时间 用逗号分隔
 Number of fish expected: maxFish
 
 枚举所有湖 以湖i为钓鱼终点 *因为不走回头路 回头是浪费时间
 思路 总是选择 每单位时间抓到的鱼最多的湖
 
 ***/
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 30;

int n, h;
int t[maxn], f[maxn], d[maxn], cf[maxn]; // cf 湖i当前五分钟能钓的鱼
int ans, sum[maxn];

void get_max(int k, int& ans, int sum[]) { // 以湖k为终点
    int maxFish = -1, id = -1;
    for (int i = 1; i <= k; ++i) {
        if (cf[i] > maxFish) {
            maxFish = cf[i]; id = i;
        }
    }
    ans += cf[id]; ++sum[id]; cf[id] -= d[id];
    if (cf[id] < 0) cf[id] = 0; // 题目挂羊头卖狗肉
}

void solve() {
    for (int i = 1; i <= n; ++i) { // 枚举终点湖
        int fish_time = h; // 用于钓鱼的时间
        for (int j = 1; j < i; ++j) fish_time -= t[j]; // 总时间减掉走路时间
        int tmp_ans = 0, tmp_sum[maxn]={0};
        memcpy(cf, f, sizeof(f));
        for (int j = 0; j < fish_time; ++j) get_max(i, tmp_ans, tmp_sum);
        if (tmp_ans > ans) {
            ans = tmp_ans; memcpy(sum, tmp_sum, sizeof(sum));
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (i > 1) printf(", ");
        printf("%d", sum[i]*5);
    }
    printf("\nNumber of fish expected: %d\n\n",ans); // Insert a blank line between cases.
}

int main() {
    while (scanf("%d", &n) && n) {
        scanf("%d", &h);
        h *= 12;
        memset(sum, 0, sizeof(sum)); ans = 0; sum[1] = h;
        sum[1] = h;
        for(int i=1;i<=n;i++) scanf("%d",&f[i]);
        for(int i=1;i<=n;i++) scanf("%d",&d[i]);
        for(int i=1;i<=n-1;i++) scanf("%d",&t[i]);
        solve();
    }
    return 0;
}

