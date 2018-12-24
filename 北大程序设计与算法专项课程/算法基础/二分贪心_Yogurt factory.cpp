#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    const long long INF = 0x3f3f3f3f;
    int n, s, c, y, m = INF; // m-某周单位生产的最小代价
    long long ans = 0;
    scanf("%d %d", &n, &s);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &c, &y);
        m = min(c, m+s); // 本周单位最小代价 直接生产c/全部用上周的库存(上周生产成本m+存储成本s)
        ans += (long long)m*y;
    }
    printf("%lld\n", ans);
    return 0;
}
