#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 10010;
int pos[maxn] = {0}, given[maxn] = {0}, dp[maxn] = {0};

int main() {
    int n, m, color, L, newL = 0; scanf("%d", &n);
    scanf("%d", &m);
    for (int i = 1; i <= m; ++i) {
        scanf("%d", &color); pos[color] = i; // 颜色映射成数字
    }
    scanf("%d", &L);
    for (int i = 0; i < L; ++i) {
        scanf("%d", &color);
        if (pos[color]) given[newL++] = pos[color]; // 剪掉eva不要的颜色同时映射数字
    }
    int ans = 0; fill(dp, dp+maxn, 1); // 最优解全部初始化为1
    for (int i = 0; i < newL; ++i) { // 遍历裁剪后的给定色块
        for (int j = 0; j < i; ++j) { // 遍历i之前的最优解 看是否能产生更优解
            if (given[i] >= given[j]) dp[i] = max(dp[j]+1, dp[i]);
        }
        ans = max(ans, dp[i]);
    }
    printf("%d\n", ans);
}
