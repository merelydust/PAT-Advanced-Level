#include <cstdio>
using namespace std;

int main() {
    int hashtable[501] = {0}; // 下标对应面额
    int n, m; scanf("%d %d", &n, &m);
    int tmp;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &tmp); hashtable[tmp]++;
    }
    bool find = false; int v1 = 0, v2 = 0;
    for (int i = 1; i <= 500 && !find; ++i) {
        if (hashtable[i] > 1) { // 处理特殊情况
            if (2 * i == m) {
                find = true; v1 = v2 = i; break;
            }
        }
        if (hashtable[i]) { // 有这个面额的硬币
            for (int j = i+1; j <= 500; ++j) {
                if (hashtable[j]) {
                    if (i + j == m) {
                        find = true; v1 = i; v2 = j; break;
                    }
                }
            }
        }
    }
    if (find) printf("%d %d\n", v1, v2);
    else printf("No Solution\n");
    return 0;
}
