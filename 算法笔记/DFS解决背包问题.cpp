// 背包问题 dfs解决
#include <cstdio>
const int maxn = 30;
int n, v, maxValue=-1; // 物品件数n 背包容量v 最大价值maxValue
int w[maxn], c[maxn]; // 每件物品重量w[i] 每件物品价值c[i]
// index为当前处理物品的序号 sumW为当前总重量 sumC为当前总价值
void DFS(int index, int sumW, int sumC) {
    if (index == n) { // 已经完成对n件物品的选择 （死胡同）
        if (sumW <= v && sumC > maxValue) maxValue = sumC;
        return;
    }
    // 岔道口
    DFS(index+1, sumW, sumC); // 不选第index件物品
    if (sumW + w[index] <= v) { // 未超过容量时 才继续选第index件物品
        if (sumC + c[index] > maxValue) maxValue = sumC + c[index];
        DFS(index+1, sumW+w[index+1], sumC+c[index]);
    }
}
   
int main() {
    scanf("%d %d", &n, &v);
    for (int i = 0; i < n; ++i) scanf("%d", &w[i]);
    for (int i = 0; i < n; ++i) scanf("%d", &c[i]);
    DFS(0, 0, 0); // 初始为第0件物品
    printf("%d\n", maxValue);
    return 0;
}
