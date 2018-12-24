#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

const int maxn = 1025;
struct node {
    int x, y, data;
}nodes[30];

int mp[maxn][maxn] = {0}; // 枚举地图上每个点 找到处理垃圾最多的

int main() {
    int d, n; scanf("%d %d", &d, &n);
    for (int i = 0; i < n; ++i) scanf("%d %d %d", &nodes[i].x, &nodes[i].y, &nodes[i].data);
    int ans = 0, nPlace = 0; // 最多处理垃圾 能达到ans的投放点数量
    for (int i = 0; i < n; ++i) {
        for (int row = nodes[i].x-d; row <= nodes[i].x + d; ++row) {
            if (row < 0 || row >= maxn) continue;
            for (int col = nodes[i].y-d; col <= nodes[i].y + d; ++col) {
                if (col < 0 || col >= maxn) continue;
                mp[row][col] += nodes[i].data; // 在该点投放能处理的垃圾数量加上d范围内垃圾点的垃圾量
                if (ans < mp[row][col]) { // 更新最多处理垃圾
                    ans = mp[row][col]; nPlace = 1;
                }
                else if (ans == mp[row][col]) ++nPlace;
            }
        }
    }
    printf("%d %d\n", nPlace, ans);
    return 0;
}
