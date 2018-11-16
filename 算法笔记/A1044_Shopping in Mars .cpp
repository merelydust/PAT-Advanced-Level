// 查找题->二分查找
// 钱的累加是单调递增的->sum[]
// 两个端点i,j之间的钱是sum[j]-sum[i-1] ->
// sum[j]-sum[i-1]=m ->sum[j] = sum[i-1]+m ->
// 枚举左端点i 查找是否存在使该等式恰好成立的右端点j
// 否则 寻找第一个大于sum[i-1]+m的sum[j]->上界

#include <cstdio>
using namespace std;

int sum[100010];
int upper_bound(int l, int r, int x) {
    int left = l, right = r, mid;
    while(left < right) {
        mid = (left + right) / 2;
        if (sum[mid] > x) right = mid;
        else left = mid + 1;
    }
    return left;
}

int main() {
    int n, m; scanf("%d %d", &n, &m);
    int nearm = 100010001; sum[0] = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &sum[i]); sum[i] += sum[i-1];
    }
    for (int i = 1; i <= n; ++i) { // 枚举左端点
        int j = upper_bound(i, n+1, sum[i-1]+m); // 找到右端点/上界
        if (sum[j-1] - sum[i-1] == m) { // 找到了恰好够付的方案
            nearm = m; break;
        }
        else if (j <=n && sum[j]-sum[i-1] < nearm) { // 大于m但更接近m的点
            nearm = sum[j]-sum[i-1]; // 更新nearm
        }
    }
    for (int i = 1; i <= n; ++i) { // 列出所有方案 m/nearm
        int j = upper_bound(i, n+1, sum[i-1]+nearm);
        if (sum[j-1]-sum[i-1] == nearm) printf("%d-%d\n", i, j-1);
    }
    return 0;
}
