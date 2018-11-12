// 区间贪心 用局部最优推得全局最优
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 110;
struct interval {
    int x, y;
}I[maxn];

bool cmp(interval a, interval b) {
    if (a.x != b.x) return a.x > b.x;
    else return a.y < b.y;
}

int main() {
    int n;
    while (scanf("%d", &n) && n != 0) {
        for (int i = 0; i < n; ++i) scanf("%d %d", &I[i].x, &I[i].y);
    }
    sort(I,I+n, cmp);
    // ans记录不相交区间个数 lastx记录上一个被选中区间的左端点
    int ans = 1, lastx = I[0].x;
    for (int i = 1; i < n; ++i) {
        if (I[i].y <= lastx) { // 区间选点问题只需要把这句改成 I[i].y < lastx
            lastx = I[i].x; ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}
