#include <cstdio>
const int maxn = 10010;
int a[maxn], dp[maxn];  // a[i]存放序列 dp[i]存放以i为结尾的连续序列最大和
int s[maxn] = {0}; // s[i]表示产生dp[i]的连续序列是从a的哪一个元素开始的

int main() {
    int n; scanf("%d", &n);
    bool flag = false; // 标记数组中是否有非负数
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        if (a[i] >= 0) flag = true;
    }
    if (!flag) {
        printf("0 %d %d\n", a[0], a[n-1]); return 0;
    }
    dp[0] = a[0]; // 边界
    for (int i = 1; i < n; ++i) {
        if (dp[i-1]+a[i] > a[i]) {
            dp[i] = dp[i-1] + a[i]; s[i] = s[i-1];
        }
        else {
            dp[i] = a[i]; s[i] = i;
        }
    }
    int k = 0; // k最优解元素的数组索引
    for (int i = 1; i < n; ++i) {
        if (dp[i] > dp[k]) k = i;
    }
    printf("%d %d %d\n", dp[k], a[s[k]], a[k]);
    return 0;
}
